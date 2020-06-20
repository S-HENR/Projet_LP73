#include "gobackhomestate.h"
#include "ant.h"
#include "warrior.h"
#include "AStar.hpp"
#include "puttingdownfoodstate.h"
#include "warrioreatingstate.h"


GoBackHomeState::GoBackHomeState(std::array<int, 2> size, std::vector<std::vector<Ground*>> board, std::array<int, 2>& _coordinates_ant, std::array<int, 2>& _coordinates_anthill) : coordinates_ant(_coordinates_ant), coordinates_anthill(_coordinates_anthill)
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
    auto path = generator.findPath({coordinates_anthill[0], coordinates_anthill[1]}, {coordinates_ant[0], coordinates_ant[1]});

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
    if(warrior.get_food_need() < 10)
        return std::make_unique<WarriorEatingState>();
    warrior.movement(); //x : steps[0][0] ; y : steps[0][1]

    //delete movement made
    steps.erase(steps.begin());

    if(steps.size() > 0)
        return nullptr;
    return std::make_unique<PuttingDownFoodState>();
}


//while(steps.size() > 0)
//{
//    std::cout << steps[0][0] << " " << steps[0][1] << std::endl;
//    steps.erase(steps.begin());
//}
