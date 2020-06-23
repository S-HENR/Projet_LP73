#include "idlequeen.h"
#include "layinganeggstate.h"
#include "queen.h"
#include <random>

IdleQueen::IdleQueen()
{

}

std::unique_ptr<State> IdleQueen::Action(Ant& ant)
{
    Queen& queen = dynamic_cast<Queen&>(ant);
    const int range_from  = 0;
    const int range_to    = 49;
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(range_from, range_to);

    queen.increase_food_need();
    queen.set_time_to_transition(queen.get_time_to_transition()-1);
    if(distr(generator) == 0)
    {
        return std::make_unique<LayingAnEggState>();
    }

//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
    return nullptr;
}

