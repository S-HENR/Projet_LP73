#include "ant.h"
#include "movingstate.h"
#include "puttingdownfoodstate.h"
#include "warrior.h"

MovingState::MovingState()
{

}

std::unique_ptr<State> MovingState::Action(Ant &ant)
{
//    struct nearby_tiles
//    {
//        Ground* tiles;
//        float prob;
//    };
//    float prob1 = 0.25, prob2 = 0.25, prob3 = 0.25, prob4 = 0.25;

//    Warrior& warrior = dynamic_cast<Warrior&>(ant);
//    warrior.increase_food_need();
//    warrior.set_time_to_transition(-1);

//    //warrior coordinates
//    int x = warrior.get_coordinates().at(0);
//    int y = warrior.get_coordinates().at(1);

//    //coordinates of the cases around the warrior
//    std::vector<nearby_tiles> tiles;
//    auto&& tile1 = warrior.get_env().getTile(x-1,y);
//    tiles.push_back(tile1, prob1);
//    auto&& tile2 = warrior.get_env().getTile(x,y+1);
//    tiles.push_back(tile2, prob1);
//    auto&& tile3 = warrior.get_env().getTile(x+1,y);
//    tiles.push_back(tile3);
//    auto&& tile4 = warrior.get_env().getTile(x,y-1);
//    tiles.push_back(tile4);

//    float prob1 = 0.25, prob2 = 0.25, prob3 = 0.25, prob4 = 0.25;

//    //if the warrior is inside the anthill, will put down the food she's carrying (if anthill capacity full or if the ant doesn't have any food on her back will be take care of in the next state
//    if(warrior.get_env().getTile(x,y)->getType() == 0)
//    {
//        return std::make_unique<PuttingDownFoodState>();
//    }
//    //if the warrior is outside the anthill and her carrying capacity is full, she's going back to the anthill to put down her food
//    else if(warrior.get_quantity_carried() >= warrior.get_carrying_capacity())
//    {
//        //return std::make_unique<GoBackHomeState>();
//    }
//    else
//    {
//        for(auto&& box: nearby_tiles)
//        {
//            switch (box->getType())
//            {
//               case 0:
//                  uppercase_A++;
//                  break;
//               case 1:
//                  lowercase_a++;
//                  break;
//              case 2:
//                 uppercase_A++;
//                 break;
//              case 3:
//                 lowercase_a++;
//                 break;
//               default:
//                 return nullptr;
//                 std::cout << "Switch case error in warrior moving state";
//            }
//        }
//    }

//    if(case1->getType() == 1 && case2->getType() == 1 && case3->getType() == 1 && case4->getType() == 1)
//    {

//    }

    //    if(false) // Une condition pr passer à un nouvelle état
    //        return std::make_unique<UnAutreEtat>();
        return nullptr;
}
