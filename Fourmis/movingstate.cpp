#include "ant.h"
#include "movingstate.h"
#include "warrior.h"

MovingState::MovingState()
{

}

std::unique_ptr<State> MovingState::Action(Ant &ant)
{
    Warrior& warrior = dynamic_cast<Warrior&>(ant);
    int x = warrior.get_coordinates().at(0);
    int y = warrior.get_coordinates().at(1);

    //tab ?
    auto&& case1 = warrior.get_env()->getTile(x-1,y);
    auto&& case2 = warrior.get_env()->getTile(x,y+1);
    auto&& case3 = warrior.get_env()->getTile(x+1,y);
    auto&& case4 = warrior.get_env()->getTile(x,y-1);

    warrior.increase_food_need();
    warrior.set_time_to_transition(-1);

    if(case1->getType() == 1 && case2->getType() == 1 && case3->getType() == 1 && case4->getType() == 1)
    {

    }

    //    if(false) // Une condition pr passer à un nouvelle état
    //        return std::make_unique<UnAutreEtat>();
        return nullptr;
}
