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
    warrior.set_time_to_transition(warrior.get_time_to_transition()-1);

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

    return std::make_unique<MovingState>();

//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
    return nullptr;
}
