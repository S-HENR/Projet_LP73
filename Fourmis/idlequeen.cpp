#include "idlequeen.h"
#include "layinganeggstate.h"
#include "queen.h"

IdleQueen::IdleQueen()
{

}

std::unique_ptr<State> IdleQueen::Action(Ant& ant)
{
    Queen& queen = dynamic_cast<Queen&>(ant);

    int rand = queen.get_env().generate_random(0, 19);

    queen.increase_food_need();
    if(rand == 0)
    {
        return std::make_unique<LayingAnEggState>();
    }

    return nullptr;
}

