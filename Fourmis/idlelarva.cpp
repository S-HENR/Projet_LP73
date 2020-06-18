#include "idlelarva.h"
#include "larva.h"

IdleLarva::IdleLarva()
{}

std::unique_ptr<State> IdleLarva::Action(Ant& ant)
{
    Larva& larva = dynamic_cast<Larva&>(ant);

    larva.increase_food_need();
    larva.set_time_to_transition(-1);

//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
    return nullptr;
}

