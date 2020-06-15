#ifndef MOVINGSTATE_H
#define MOVINGSTATE_H

#include "state.h"


class MovingState : public State
{
public:
    MovingState();
    ~MovingState(){};

    // StateWarrior interface
public:
    std::unique_ptr<State> Action(Ant &ant) override;
};

#endif // MOVINGSTATE_H
