#include "queen.h"

Queen::Queen()
{

}

Queen::Queen(int _food_need, int _max_food_need, int _time_to_transition, bool _is_queen) :
    Ant(_food_need, _max_food_need, _time_to_transition, _is_queen)
{

}

Queen::~Queen()
{

}

int Queen::increase_food_need()
{
    return 0;
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
