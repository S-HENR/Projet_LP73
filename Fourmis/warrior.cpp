#include "movingstate.h"
#include "warrior.h"

Warrior::Warrior(Environnement& _env, Anthill* _anthill, bool _is_queen, int _max_food_need, int _time_to_transition, int _carrying_capacity, int _food_need) :
    Ant(_env, _anthill, _is_queen, _max_food_need, _time_to_transition,_food_need, std::make_unique<MovingState>()), carrying_capacity(_carrying_capacity)
{

}

Warrior::~Warrior()
{

}

void Warrior::increase_food_need()
{
    set_food_need(get_food_need() + 1 );
}

void Warrior::eat()
{

}

int Warrior::get_quantity_carried() const
{
    return quantity_carried;
}

void Warrior::increase_quantity_carried(int value)
{
    quantity_carried += value;
}

void Warrior::decrease_quantity_carried(int value)
{
    quantity_carried -= value;
}

int Warrior::get_carrying_capacity() const
{
    return carrying_capacity;
}

void Warrior::set_carrying_capacity(int value)
{
    carrying_capacity = value;
}

void Warrior::movement(const int x, const int y)
{
    set_coordinates(x, y);
}

void Warrior::lay_pheromone()
{
    auto* tile = get_env().getTile(get_coordinates().x, get_coordinates().y);
    Dirt* dirt_tile = dynamic_cast<Dirt*>(tile);

    dirt_tile->set_pheromone_rate(100);
}
