#include "pickingupfoodstate.h"
#include "ant.h"
#include "warrior.h"
#include "movingstate.h"
#include "gobackhomestate.h"

PickingUpFoodState::PickingUpFoodState(Food& tile) : food_tile(tile)
{

}

std::unique_ptr<State> PickingUpFoodState::Action(Ant& ant)
{
    Warrior& warrior = dynamic_cast<Warrior&>(ant);
    warrior.increase_food_need();

    int rest_warrior_carrying_capacity = warrior.get_carrying_capacity() - warrior.get_quantity_carried();

    const auto& board = warrior.get_env().get_board();
    std::array<int, 2> size = {
        static_cast<int>(board.size()),
        static_cast<int>(board[0].size())
    };

    if(food_tile.get_quantity_food() > 0)
    {
          int amount = warrior.get_env().collect_food(food_tile.get_coordinates().x, food_tile.get_coordinates().y, rest_warrior_carrying_capacity);
          warrior.increase_quantity_carried(amount);
    }

    if(warrior.get_quantity_carried() >= warrior.get_carrying_capacity())
    {
        return std::make_unique<GoBackHomeState>(size, board, warrior.get_coordinates(), warrior.get_anthill()->get_coordinates());
    }
    return std::make_unique<MovingState>();
}
