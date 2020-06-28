#include "puttingdownfoodstate.h"
#include "ant.h"
#include "warrior.h"
#include "movingstate.h"

PuttingDownFoodState::PuttingDownFoodState()
{

}

std::unique_ptr<State> PuttingDownFoodState::Action(Ant& ant)
{
    Warrior& warrior = dynamic_cast<Warrior&>(ant);
    warrior.increase_food_need();

    int rest_anthill_capacity_stock = warrior.get_anthill()->get_max_quantity_food_stock() - warrior.get_anthill()->get_quantity_food_stock();

    if(rest_anthill_capacity_stock > 0)
    {
        if(warrior.get_quantity_carried() > rest_anthill_capacity_stock)
        {
            warrior.get_anthill()->increase_quantity_food_stock(rest_anthill_capacity_stock);
            warrior.decrease_quantity_carried(rest_anthill_capacity_stock);
        }
        else
        {
            warrior.get_anthill()->increase_quantity_food_stock(warrior.get_quantity_carried());
            warrior.decrease_quantity_carried(warrior.get_quantity_carried());
        }
    }
    warrior.set_quantity_carried(0);
    return std::make_unique<MovingState>();
}
