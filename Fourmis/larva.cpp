#include "larva.h"

Larva::Larva(Environnement& _env, Anthill* _anthill, bool _is_queen, int _food_need, int _max_food_need, int _time_to_transition, bool _is_being_fed) :
    DependentAnt(_env, _anthill, _is_queen, _food_need, _max_food_need, _time_to_transition, _is_being_fed)
{

}

Larva::~Larva()
{

}

void Larva::increase_food_need()
{
    this->set_food_need(this->get_food_need() + 1 );
}

void Larva::eat()
{

}
