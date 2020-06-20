#include "ant.h"
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
    warrior.set_time_to_transition(-1);

    //warrior coordinates
    int x = warrior.get_coordinates()[0];
    int y = warrior.get_coordinates()[1];

    //coordinates of the cases around the warrior and the probabilities the ants will choose to move on this tile
    std::vector<nearby_tiles> tiles = get_nearby_tiles(&warrior);

    //if the warrior is inside the anthill, will put down the food she's carrying (if anthill capacity full or if the ant doesn't have any food on her back will be take care of in the next state
    if(warrior.get_env().getTile(x,y)->getType() == 0)
    {
        return std::make_unique<PuttingDownFoodState>();
    }
    //if the warrior is outside the anthill and her carrying capacity is full, she's going back to the anthill to put down her food
    else if(warrior.get_quantity_carried() >= warrior.get_carrying_capacity())
    {
        //return std::make_unique<GoBackHomeState>();
    }

    //if the warrior is outside the anthill and her carrying capacity is not full
    else
    {
        //examining the tiles around the ant to see if there is food, obstacle or pheromone on dirt tiles
        for(auto&& box: tiles)
        {
            //if tile is not dirt/food, the var will be null
            Dirt& dirt_tile = dynamic_cast<Dirt&>(*box.tiles);
            Food& food_tile = dynamic_cast<Food&>(*box.tiles);

            switch (box.tiles->getType())
            {
               //case anthill, prob = 0, if its capacity is not full, we do not want her to go back inside
               case 0:
                  box.prob = 0;
                  break;
               //case dirt, increase the prob according to presence of pheromone
               case 1:
                  box.prob += box.prob * dirt_tile.get_pheromone_rate();
                  break;
              //case obstacle, prob = 0, cannot go
              case 2:
                  box.prob = 0;
                  break;
              //case food
              case 3:
                  //if warrior is hungry
                  if (warrior.get_max_food_need() - warrior.get_food_need() <= 10)
                  {
                      return std::make_unique<WarriorEatingState>(food_tile);
                  }
                  //if warrior is not angry and can still pick up food
                  else
                  {
                      return std::make_unique<PickingUpFoodState>(food_tile);
                  }

                 break;
               default:
                 return nullptr;
                 std::cout << "Switch case error in warrior moving state";
            }
        }

        //recalculating probs (because for now it can be over 100)
        float sum_prob = tiles[0].prob + tiles[1].prob + tiles[2].prob + tiles[3].prob;
        for(auto&& box: tiles)
        {
            box.prob = box.prob / sum_prob;
        }

        //generating a random number to pick a tile according to the probs
        const int range_from  = 1;
        const int range_to    = 100;
        std::random_device rand_dev;
        std::mt19937 generator(rand_dev());
        std::uniform_int_distribution<int> distr(range_from, range_to);

        float lower_threshold = 1;
        float upper_threshold = 0;
        for(auto&& box: tiles)
        {
            upper_threshold += box.prob;
            if((distr(generator) >= lower_threshold) && (distr(generator) <= upper_threshold))
            {
                warrior.movement();
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
    int x = _warrior->get_coordinates()[0];
    int y = _warrior->get_coordinates()[1];

    std::vector<nearby_tiles> tiles;
    nearby_tiles tile1 = {_warrior->get_env().getTile(x-1,y), 0.25};
    tiles.push_back(tile1);
    nearby_tiles tile2 = {_warrior->get_env().getTile(x,y+1), 0.25};
    tiles.push_back(tile2);
    nearby_tiles tile3 = {_warrior->get_env().getTile(x+1,y), 0.25};
    tiles.push_back(tile3);
    nearby_tiles tile4 = {_warrior->get_env().getTile(x,y-1), 0.25};
    tiles.push_back(tile4);

    return tiles;
}
