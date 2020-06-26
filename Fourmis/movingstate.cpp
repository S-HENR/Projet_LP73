#include "ant.h"
#include "gobackhomestate.h"
#include "movingstate.h"
#include "pickingupfoodstate.h"
#include "puttingdownfoodstate.h"
#include "warrior.h"
#include "warrioreatingstate.h"

#include <random>

MovingState::MovingState()
{

}

std::unique_ptr<State> MovingState::Action(Ant &ant)
{
    Warrior& warrior = dynamic_cast<Warrior&>(ant);
    warrior.increase_food_need();

    //warrior coordinates
    int x = warrior.get_coordinates().x;
    int y = warrior.get_coordinates().y;

    //coordinates of the cases around the warrior and the probabilities the ants will choose to move on this tile
    std::vector<nearby_tiles> tiles = get_nearby_tiles(&warrior);

    const auto& board = warrior.get_env().get_board();
    std::array<int, 2> size = {
        static_cast<int>(board.size()),
        static_cast<int>(board[0].size())
    };

    //if the warrior is inside the anthill, will put down the food she's carrying (if anthill capacity full or if the ant doesn't have any food on her back will be take care of in the next state
    if((warrior.get_env().getTile(x,y)->getType() == 0) && (warrior.get_quantity_carried() > 0))
    {
        return std::make_unique<PuttingDownFoodState>();
    }
    //if the warrior is outside the anthill and her carrying capacity is full AND she's not hungry, she's going back to the anthill to put down her food
    else if((warrior.get_quantity_carried() >= warrior.get_carrying_capacity()) && !(warrior.get_max_food_need() - warrior.get_food_need() <= 5))
    {
        return std::make_unique<GoBackHomeState>(size, board, warrior.get_coordinates(), warrior.get_anthill()->get_coordinates());
    }
    //if the warrior is outside the anthill and her carrying capacity is not full
    else
    {
        //examining the tiles around the ant to see if there is food, obstacle or pheromone on dirt tiles
        for(auto& box: tiles)
        {
            //if tile is not dirt/food, the var will be null
            Dirt* dirt_tile = dynamic_cast<Dirt*>(box.tile);
            Food* food_tile = dynamic_cast<Food*>(box.tile);

            switch (box.tile->getType())
            {
               //case anthill, prob = 0, if its capacity is not full, we do not want her to go back inside
               case 0:
                  box.prob = 0;
                  break;
               //case dirt, increase the prob according to presence of pheromone
               case 1:
                  //box.prob += box.prob * dirt_tile->get_pheromone_rate();
                  break;
              //case obstacle, prob = 0, cannot go
              case 2:
                  box.prob = 0;
                  break;
              //case food
              case 3:
                {
                  //if warrior is hungry
                  if ((warrior.get_max_food_need() - warrior.get_food_need()) <= 5)
                  {
                      return std::make_unique<WarriorEatingState>(*food_tile);
                  }
                  //if warrior is not angry and can still pick up food
                  else if (warrior.get_quantity_carried() < warrior.get_carrying_capacity())
                  {
                      return std::make_unique<PickingUpFoodState>(*food_tile);
                  }

                 break;
                }
               default:
                 std::cout << "Switch case error in warrior moving state";
                 return nullptr;
            }
        }

        //recalculating probs (because for now it can be over 100)
        float sum_prob = 0;

        for(auto& box: tiles)
        {
            sum_prob += box.prob;
        }

        for(auto& box: tiles)
        {
            box.prob = (box.prob / sum_prob) * 100;
        }

        //generating a random number to pick a tile according to the probs
        int rand = warrior.get_env().generate_random(1, 100);

        float lower_threshold = 1;
        float upper_threshold = 0;

        for(auto& box: tiles)
        {
            upper_threshold += box.prob;

            if((rand >= lower_threshold) && (rand <= upper_threshold))
            {
                //display the ant's tile picture without the ant on it

                switch (warrior.get_env().getTile(warrior.get_coordinates().x, warrior.get_coordinates().y)->getType())
                {
                   //case anthill
                   case 0:
                      break;
                   //case dirt
                   case 1:
                      warrior.get_env().get_map().refresh_display(0, warrior.get_coordinates().x, warrior.get_coordinates().y);
                      break;
                  //case obstacle
                  case 2:
                      break;
                  //case food
                  case 3:
                      warrior.get_env().get_map().refresh_display(1, warrior.get_coordinates().x, warrior.get_coordinates().y);
                     break;
                   default:
                     return nullptr;
                     std::cout << "Switch case 2 error in warrior moving state";
                }

                //moving the ant
                warrior.movement(box.tile->get_coordinates().x, box.tile->get_coordinates().y);

                //displaying the ant pictures on its new tile

                //handle west and east movement
                switch(box.tile->get_coordinates().x - x)
                {
                case -1:
                    warrior.get_env().get_map().refresh_display(5, box.tile->get_coordinates().x, box.tile->get_coordinates().y);
                    break;
                case 1:
                    warrior.get_env().get_map().refresh_display(3, box.tile->get_coordinates().x, box.tile->get_coordinates().y);
                    break;
                default:
                    break;
                }

                //handle north and south movement
                switch(box.tile->get_coordinates().y - y)
                {
                case -1:
                    warrior.get_env().get_map().refresh_display(2, box.tile->get_coordinates().x, box.tile->get_coordinates().y);
                    break;
                case 1:
                    warrior.get_env().get_map().refresh_display(4, box.tile->get_coordinates().x, box.tile->get_coordinates().y);
                    break;
                default:
                    break;
                }

                return nullptr;
            }
            lower_threshold += box.prob;
        }
    }
    //    if(false) // Une condition pr passer à un nouvelle état
    //        return std::make_unique<UnAutreEtat>();
        return nullptr;
}

std::vector<nearby_tiles> MovingState::get_nearby_tiles(Warrior* _warrior)
{
    //warrior coordinates
    int x = _warrior->get_coordinates().x;
    int y = _warrior->get_coordinates().y;

    int max_x = _warrior->get_env().getSizeX();
    int max_y = _warrior->get_env().getSizeY();

    coord new_coord1 = {x-1,y};
    coord new_coord2 = {x,y+1};
    coord new_coord3 = {x+1,y};
    coord new_coord4 = {x,y-1};

    std::vector<nearby_tiles> tiles;

    auto check_bounds = [max_x, max_y, _warrior, &tiles](const coord& new_coord){
        if(new_coord.x >= 0 && new_coord.x < max_x && new_coord.y >= 0 && new_coord.y < max_y)
        {
            nearby_tiles tile = {_warrior->get_env().getTile(new_coord.x, new_coord.y), 0.25};
            tiles.push_back(tile);
        }
    };

    check_bounds(new_coord1);
    check_bounds(new_coord2);
    check_bounds(new_coord3);
    check_bounds(new_coord4);

    return tiles;
}
