#ifndef PUTTINGDOWNFOODSTATE_H
#define PUTTINGDOWNFOODSTATE_H

#include "state.h"



class PuttingDownFoodState : public State
{
public:
    PuttingDownFoodState();
    ~PuttingDownFoodState(){};

    // StateWarrior interface
public:
    std::unique_ptr<State> Action(Ant &ant);
};

#endif // PUTTINGDOWNFOODSTATE_H
