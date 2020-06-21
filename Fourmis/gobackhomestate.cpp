#include "gobackhomestate.h"
#include "ant.h"
#include "warrior.h"
#include "AStar.hpp"
#include "puttingdownfoodstate.h"
#include "movingstate.h"


GoBackHomeState::GoBackHomeState(std::array<int, 2> size, std::vector<std::vector<Ground*>> board, coord& _coordinates_ant, coord& _coordinates_anthill) :
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
        for(int j = 0 ; j < size[0] ; i++)
            if(!board[i][j]->getCrossable())
                generator.addCollision({i,j});

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
    warrior.set_time_to_transition(-1);

    if(warrior.get_food_need() < 10)
    {
        //use to be warrioreatingstate but need to be near a food case to be able to eat
        return std::make_unique<MovingState>();
    }
    //warrior.movement(); //x : steps[0][0] ; y : steps[0][1]

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
