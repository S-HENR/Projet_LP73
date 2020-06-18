#include "queen.h"

Queen::Queen()
{

}

Queen::Queen(Anthill* _anthill, bool _is_queen, int _food_need, int _max_food_need, int _time_to_transition, bool _is_being_fed) :
    DependentAnt(_anthill, _is_queen, _food_need, _max_food_need, _time_to_transition, _is_being_fed)
{

}

Queen::~Queen()
{

}

void Queen::increase_food_need()
{
    this->set_food_need(this->get_food_need() + 1 );
}

void Queen::eat()
{

}
