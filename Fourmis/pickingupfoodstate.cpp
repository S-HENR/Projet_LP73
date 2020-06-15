#include "pickingupfoodstate.h"
#include "ant.h"
#include "warrior.h"

PickingUpFoodState::PickingUpFoodState()
{

}

std::unique_ptr<State> PickingUpFoodState::Action(Ant& ant)
{
    Warrior& warrior = dynamic_cast<Warrior&>(ant);

//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
    return nullptr;
}
