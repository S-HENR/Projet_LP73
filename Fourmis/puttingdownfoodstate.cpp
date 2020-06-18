#include "puttingdownfoodstate.h"
#include "ant.h"
#include "warrior.h"

PuttingDownFoodState::PuttingDownFoodState()
{

}

std::unique_ptr<State> PuttingDownFoodState::Action(Ant& ant)
{
    Warrior& warrior = dynamic_cast<Warrior&>(ant);
    warrior.increase_food_need();
    warrior.set_time_to_transition(-1);

//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
    return nullptr;
}
