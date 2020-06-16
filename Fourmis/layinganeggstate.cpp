#include "layinganeggstate.h"
#include "ant.h"
#include "queen.h"
#include "idlequeen.h"
#include "egg.h"
#include <random>

LayingAnEggState::LayingAnEggState()
{

}

std::unique_ptr<State> LayingAnEggState::Action(Ant& ant)
{
    Queen& queen = dynamic_cast<Queen&>(ant);

    const int range_from  = 0;
    const int range_to    = 499;
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(range_from, range_to);

    queen.increase_food_need();
    if( (distr(generator) == 0) )
    {
        Egg(queen.get_anthill(), true);
    }
    else
    {
        Egg(queen.get_anthill(), false);
    }
    return std::make_unique<IdleQueen>();

//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
    return nullptr;
}
