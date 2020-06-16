#include "idlelarva.h"
#include "larva.h"

IdleLarva::IdleLarva()
{}

std::unique_ptr<State> IdleLarva::Action(Ant& ant)
{
    Larva& larva = dynamic_cast<Larva&>(ant);

    if( larva.get_max_food_need() - larva.get_food_need() <= 10 )
    {
        larva.set_is_hungry(true);
    }
    larva.increase_food_need();

//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
    return nullptr;
}

