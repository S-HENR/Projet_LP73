#include "dependentant.h"

DependentAnt::DependentAnt(Environnement& _env, Anthill* _anthill, bool _is_queen, int _food_need, int _max_food_need, int _time_to_transition, bool _is_being_fed) :
    Ant(_env, _anthill, _is_queen, _food_need, _max_food_need, _time_to_transition)
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
