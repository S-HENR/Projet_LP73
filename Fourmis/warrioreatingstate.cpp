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

    if(food_tile.get_quantity_food() > 0)
    {
        int amount = warrior.get_env().collect_food(food_tile.get_coordinates().x, food_tile.get_coordinates().y, warrior.get_food_need());
        warrior.decrease_food_need(amount);

    }
    return std::make_unique<MovingState>();
}
