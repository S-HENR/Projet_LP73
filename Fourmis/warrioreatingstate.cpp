#include "warrior.h"
#include "warrioreatingstate.h"

WarriorEatingState::WarriorEatingState()
{

}

std::unique_ptr<State> WarriorEatingState::Action(Ant& ant)
{
    Warrior& warrior = dynamic_cast<Warrior&>(ant);

//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
    return nullptr;
}
