#include "layinganeggstate.h"
#include "ant.h"
#include "queen.h"
#include "idlequeen.h"
#include "egg.h"

LayingAnEggState::LayingAnEggState()
{

}

std::unique_ptr<State> LayingAnEggState::Action(Ant& ant)
{
    Queen& queen = dynamic_cast<Queen&>(ant);

    queen.increase_food_need();

    if( queen.get_anthill()->get_ants().size() == static_cast<size_t>(queen.get_anthill()->get_max_ants_nb() - 1) && (queen.get_anthill()->queens_counter() < 2))
    {
        //Egg e = Egg(queen.get_env(), queen.get_anthill(), true);
        //queen.get_anthill()->get_ants().emplace_back(e);
    }
    else if( queen.get_anthill()->get_ants().size() < static_cast<size_t>(queen.get_anthill()->get_max_ants_nb() - 1))
    {
        //Egg e = Egg(queen.get_env(), queen.get_anthill(), false);
        //queen.get_anthill()->get_ants().emplace_back(e);
    }
    return std::make_unique<IdleQueen>();

//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
}
