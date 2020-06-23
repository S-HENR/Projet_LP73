#include "movingstate.h"
#include "warrior.h"
#include "warrioreatingstate.h"

WarriorEatingState::WarriorEatingState(Food& tile) : food_tile(tile)
{

}


std::unique_ptr<State> WarriorEatingState::Action(Ant& ant)
{
    Warrior& warrior = dynamic_cast<Warrior&>(ant);
    warrior.increase_food_need();
    warrior.set_time_to_transition(warrior.get_time_to_transition()-1);

    if(food_tile.get_quantity_food() > 0)
    {
//        if(food_tile.get_quantity_food() >= warrior.get_food_need())
//        {
//            //if the tile has enough food to fully satisfy the ant's needs
//            warrior.decrease_food_need(warrior.get_food_need());
//            food_tile.decrease_quantity(warrior.get_food_need());
//        }
//        else
//        {
//            //if the tile has not enough food to fully satisfy the ant's needs
//            warrior.decrease_food_need(food_tile.get_quantity_food());
//            food_tile.decrease_quantity(food_tile.get_quantity_food());
//        }

        int amount = warrior.get_env().collect_food(food_tile.get_coordinates().x, food_tile.get_coordinates().y, warrior.get_food_need());
        warrior.decrease_food_need(amount);

    }
    return std::make_unique<MovingState>();

//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
    return nullptr;
}
