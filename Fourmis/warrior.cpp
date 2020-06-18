#include "warrior.h"

Warrior::Warrior()
{

}

Warrior::Warrior(Environnement* _env, Anthill* _anthill, bool _is_queen, int _food_need, int _max_food_need, int _time_to_transition) :
    Ant(_env, _anthill, _is_queen, _food_need, _max_food_need, _time_to_transition)
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

int Warrior::get_quantity_carried() const
{
    return quantity_carried;
}

void Warrior::set_quantity_carried(int value)
{
    quantity_carried = value;
}

int Warrior::get_carrying_capacity() const
{
    return carrying_capacity;
}

void Warrior::set_carrying_capacity(int value)
{
    carrying_capacity = value;
}

void Warrior::movement()
{

}

void Warrior::lay_pheromone()
{

}
