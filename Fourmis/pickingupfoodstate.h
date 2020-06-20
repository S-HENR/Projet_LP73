#ifndef PICKINGUPFOODSTATE_H
#define PICKINGUPFOODSTATE_H

#include "food.h"
#include "state.h"



class PickingUpFoodState : public State
{
public:
    PickingUpFoodState() = delete;
    PickingUpFoodState(Food& tile);
    ~PickingUpFoodState(){};

    // StateWarrior interface
public:
    std::unique_ptr<State> Action(Ant &ant);

private:
    Food&  food_tile;
};

#endif // PICKINGUPFOODSTATE_H
