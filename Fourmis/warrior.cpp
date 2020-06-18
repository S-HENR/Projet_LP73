#include "warrior.h"

Warrior::Warrior()
{

}

Warrior::Warrior(Anthill* _anthill, bool _is_queen, int _food_need, int _max_food_need, int _time_to_transition) :
    Ant(_anthill, _is_queen, _food_need, _max_food_need, _time_to_transition)
{

}

Warrior::~Warrior()
{

}

void Warrior::increase_food_need()
{
    this->set_food_need(this->get_food_need() + 1 );
}

void Warrior::eat()
{

}

void Warrior::movement()
{

}

void Warrior::lay_pheromone()
{

}
