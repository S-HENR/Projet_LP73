#include "egg.h"
#include "idleegg.h"

IdleEgg::IdleEgg()
{

}

std::unique_ptr<State> IdleEgg::Action(Ant& ant)
{
    Egg& egg = dynamic_cast<Egg&>(ant);

    egg.set_time_to_transition(egg.get_time_to_transition()-1);

//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
    return nullptr;
}
