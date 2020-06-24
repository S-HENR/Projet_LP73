#include "gobackhomestate.h"
#include "ant.h"
#include "warrior.h"
#include "AStar.hpp"
#include "puttingdownfoodstate.h"
#include "movingstate.h"


GoBackHomeState::GoBackHomeState(std::array<int, 2> size, const std::vector<std::vector<Ground*>>& board, const coord& _coordinates_ant, const coord& _coordinates_anthill) :
    coordinates_ant{.x = _coordinates_ant.x, .y = _coordinates_ant.y},
    coordinates_anthill{.x = _coordinates_anthill.x, .y = _coordinates_anthill.y}
{
    AStar::Generator generator;
    // Set 2d map size.
    generator.setWorldSize({size[1],size[0]});
    // You can use a few heuristics : manhattan, euclidean or octagonal.
    generator.setHeuristic(AStar::Heuristic::euclidean);
    generator.setDiagonalMovement(false);


    for(int i = 0 ; i < size[1] ; i++)
    {
        for(int j = 0 ; j < size[0] ; j++)
        {
            if(!board[i][j]->getCrossable())
                generator.addCollision({i,j});
        }
    }


    // This method returns vector of coordinates from target to source.
    auto path = generator.findPath({coordinates_anthill.x, coordinates_anthill.y}, {coordinates_ant.x, coordinates_ant.y});

    std::vector<int> coordinates(2);

    for(auto& coordinate : path) {
        coordinates[0] = coordinate.x;
        coordinates[1] = coordinate.y;
        steps.push_back(coordinates);
    }
}


std::unique_ptr<State> GoBackHomeState::Action(Ant& ant)
{
    Warrior& warrior = dynamic_cast<Warrior&>(ant);

    warrior.increase_food_need();
    warrior.set_time_to_transition(warrior.get_time_to_transition()-1);

    if((warrior.get_max_food_need() - warrior.get_food_need()) <= 5)
    {
        //use to be warrioreatingstate but need to be near a food case to be able to eat
        return std::make_unique<MovingState>();
    }

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
         std::cout << "Switch case error in warrior moving state";
         return nullptr;
    }

    //if tile is dirt then lay pheromone
    if(warrior.get_env().getTile(warrior.get_coordinates().x, warrior.get_coordinates().y)->getType() == 1){
        warrior.lay_pheromone();
    }

    //ant moves
    warrior.movement(steps[0][0], steps[0][1]);

    //if new tile is anthill, do not display ant picture, if not, display ant
    //not testing if obstacle because cannot be crossed by ants
    if(warrior.get_env().getTile(warrior.get_coordinates().x, warrior.get_coordinates().y)->getType() != 0){
        warrior.get_env().get_map().refresh_display(3, warrior.get_coordinates().x, warrior.get_coordinates().y);
    }

    //delete movement made
    steps.erase(steps.begin());

    if(steps.size() > 0)
    {
        return nullptr;
    }
    return std::make_unique<PuttingDownFoodState>();
}


//while(steps.size() > 0)
//{
//    std::cout << steps[0][0] << " " << steps[0][1] << std::endl;
//    steps.erase(steps.begin());
//}
