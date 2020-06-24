#include "idlelarva.h"
#include "larva.h"

Larva::Larva(Environnement& _env, Anthill* _anthill, bool _is_queen, int _max_food_need, int _time_to_transition, float _food_need, bool _is_being_fed) :
    DependentAnt(_env, _anthill, _is_queen, _max_food_need, _time_to_transition,_food_need, _is_being_fed,  std::make_unique<IdleLarva>())
{

}

Larva::~Larva()
{

}

void Larva::increase_food_need()
{
    set_food_need(get_food_need() + 0.25 );
}

void Larva::eat()
{

}
