#include "queen.h"

Queen::Queen()
{

}

Queen::Queen(bool _is_queen, int _food_need, int _max_food_need, int _time_to_transition) :
    Ant(_is_queen, _food_need, _max_food_need, _time_to_transition)
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

bool Queen::get_is_hungry() const
{
    return is_hungry;
}

void Queen::set_is_hungry(bool value)
{
    is_hungry = value;
}
