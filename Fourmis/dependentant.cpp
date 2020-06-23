#include "dependentant.h"

DependentAnt::DependentAnt(Environnement& _env, Anthill* _anthill, bool _is_queen, int _max_food_need, int _time_to_transition, int _food_need, bool _is_being_fed, std::unique_ptr<State> _state) :
    Ant(_env, _anthill, _is_queen, _max_food_need, _time_to_transition,_food_need, std::move(_state)), is_being_fed(_is_being_fed)
{

}

DependentAnt::~DependentAnt()
{

}

bool DependentAnt::get_is_being_fed() const
{
    return is_being_fed;
}

void DependentAnt::set_is_being_fed(bool value)
{
    is_being_fed = value;
}
