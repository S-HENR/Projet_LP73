#include "idlewarrior.h"
#include "warrior.h"

IdleWarrior::IdleWarrior()
{

}

std::unique_ptr<State> IdleWarrior::Action(Ant& ant)
{
    Warrior& warrior = dynamic_cast<Warrior&>(ant);
    warrior.increase_food_need();
    warrior.set_time_to_transition(warrior.get_time_to_transition()-1);

//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
    return nullptr;
}
