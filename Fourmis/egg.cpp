#include "egg.h"
#include "idleegg.h"

Egg::Egg(Environnement& _env, Anthill* _anthill, bool _is_queen, int _max_food_need, int _time_to_transition, int _food_need) :
    Ant(_env, _anthill, _is_queen, _max_food_need, _time_to_transition,_food_need, std::make_unique<IdleEgg>())
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

int Egg::getType()
{
    return 0;
}
