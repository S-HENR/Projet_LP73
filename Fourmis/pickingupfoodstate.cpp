#include "pickingupfoodstate.h"
#include "ant.h"
#include "warrior.h"
#include "movingstate.h"

PickingUpFoodState::PickingUpFoodState(Food& tile) : food_tile(tile)
{

}

std::unique_ptr<State> PickingUpFoodState::Action(Ant& ant)
{
    Warrior& warrior = dynamic_cast<Warrior&>(ant);
    warrior.increase_food_need();
    warrior.set_time_to_transition(-1);

    int rest_warrior_carrying_capacity = warrior.get_carrying_capacity() - warrior.get_quantity_carried();

    if(food_tile.get_quantity_food() > 0)
    {
        if(food_tile.get_quantity_food() <= rest_warrior_carrying_capacity)
        {
            //if the tile has not enough food to fill the carrying capacity of the ants
            warrior.increase_quantity_carried(food_tile.get_quantity_food());
            food_tile.decrease_quantity(food_tile.get_quantity_food());
        }
        else
        {
            //if the hut has enough food to fill the carrying capacity of the ants
            warrior.increase_quantity_carried(rest_warrior_carrying_capacity);
            food_tile.decrease_quantity(rest_warrior_carrying_capacity);
        }
    }

    if(warrior.get_quantity_carried() >= warrior.get_carrying_capacity())
    {
        //return std::make_unique<GoBackHomeState>();
    }
    else
    {
        return std::make_unique<MovingState>();
    }


//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
    return nullptr;
}
