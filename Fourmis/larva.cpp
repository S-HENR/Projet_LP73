#include "larva.h"

Larva::Larva()
{

}

Larva::Larva(int _food_need, int _max_food_need, int _time_to_transition, bool _is_queen) :
    Ant(_food_need, _max_food_need, _time_to_transition, _is_queen)
{

}

Larva::~Larva()
{

}

int Larva::increase_food_need()
{
    return 0;
}

void Larva::eat()
{

}

bool Larva::get_is_hungry() const
{
    return is_hungry;
}

void Larva::set_is_hungry(bool value)
{
    is_hungry = value;
}
