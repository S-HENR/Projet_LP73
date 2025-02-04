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

    if( queen.get_anthill()->get_ants().size() < static_cast<size_t>(queen.get_anthill()->get_max_ants_nb() - 1))
    {
        queen.get_env().get_to_recreate().insert(std::pair<int, bool>(-1, false));
    }
    return std::make_unique<IdleQueen>();
}
