#include "idlewarrior.h"
#include "warrior.h"

IdleWarrior::IdleWarrior()
{

}

std::unique_ptr<State> IdleWarrior::Action(Ant& ant)
{
    Warrior& warrior = dynamic_cast<Warrior&>(ant);
    warrior.increase_food_need();

//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
    return nullptr;
}
