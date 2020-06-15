#ifndef PICKINGUPFOODSTATE_H
#define PICKINGUPFOODSTATE_H

#include "state.h"



class PickingUpFoodState : public State
{
public:
    PickingUpFoodState();
    ~PickingUpFoodState(){};

    // StateWarrior interface
public:
    std::unique_ptr<State> Action(Ant &ant);
};

#endif // PICKINGUPFOODSTATE_H
