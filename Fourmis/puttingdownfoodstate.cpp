#include "puttingdownfoodstate.h"
#include "ant.h"
#include "warrior.h"

PuttingDownFoodState::PuttingDownFoodState()
{

}

std::unique_ptr<State> PuttingDownFoodState::Action(Ant& ant)
{
    Warrior& warrior = dynamic_cast<Warrior&>(ant);

//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
    return nullptr;
}
