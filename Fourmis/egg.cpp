#include "egg.h"

Egg::Egg()
{

}

Egg::Egg(Environnement* _env, Anthill* _anthill, bool _is_queen, int _food_need, int _max_food_need, int _time_to_transition) :
    Ant(_env, _anthill, _is_queen, _food_need, _max_food_need, _time_to_transition)
{

}

Egg::~Egg()
{

}

void Egg::increase_food_need()
{

}

void Egg::eat()
{

}
