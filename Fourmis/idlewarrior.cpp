#include "idlewarrior.h"
#include "warrior.h"

IdleWarrior::IdleWarrior()
{

}

std::unique_ptr<State> IdleWarrior::Action(Ant& ant)
{
    Warrior& warrior = dynamic_cast<Warrior&>(ant);
    warrior.increase_food_need();

    return nullptr;
}
