#include "idlequeen.h"
#include "queen.h"

Queen::Queen(Environnement& _env, Anthill* _anthill, bool _is_queen, int _max_food_need, int _time_to_transition, int _food_need, bool _is_being_fed) :
    DependentAnt(_env, _anthill, _is_queen, _max_food_need, _time_to_transition,_food_need, _is_being_fed, std::make_unique<IdleQueen>())
{

}

Queen::~Queen()
{

}

void Queen::increase_food_need()
{
    set_food_need(get_food_need() + 1 );
}

void Queen::eat()
{

}
