#include "warrior.h"

Warrior::Warrior()
{

}

Warrior::Warrior(int _food_need, int _max_food_need, int _time_to_transition, bool _is_queen) :
    Ant(_food_need, _max_food_need, _time_to_transition, _is_queen)
{

}

Warrior::~Warrior()
{

}

int Warrior::increase_food_need()
{
    return 0;
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
