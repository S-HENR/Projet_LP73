#include "idlequeen.h"
#include "layinganeggstate.h"
#include "queen.h"

IdleQueen::IdleQueen()
{

}

std::unique_ptr<State> IdleQueen::Action(Ant& ant)
{
    Queen& queen = dynamic_cast<Queen&>(ant);

    int rand = queen.get_env().generate_random(0, 1000);

    queen.increase_food_need();
    queen.set_time_to_transition(queen.get_time_to_transition()-1);
    if(rand == 0)
    {
        return std::make_unique<LayingAnEggState>();
    }

//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
    return nullptr;
}

