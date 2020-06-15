#include "egg.h"

Egg::Egg()
{

}

Egg::Egg(int _food_need, int _max_food_need, int _time_to_transition, bool _is_queen) :
    Ant(_food_need, _max_food_need, _time_to_transition, _is_queen)
{

}

Egg::~Egg()
{

}

int Egg::increase_food_need()
{
    return 0;
}

void Egg::eat()
{

}
