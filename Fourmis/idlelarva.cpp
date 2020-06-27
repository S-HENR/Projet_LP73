#include "idlelarva.h"
#include "larva.h"

IdleLarva::IdleLarva()
{}

std::unique_ptr<State> IdleLarva::Action(Ant& ant)
{
    Larva& larva = dynamic_cast<Larva&>(ant);

    larva.increase_food_need();

    return nullptr;
}

