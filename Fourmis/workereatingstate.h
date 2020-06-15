#ifndef EATINGSTATE_H
#define EATINGSTATE_H

#include "state.h"


class WorkerEatingState : public State
{
public:
    WorkerEatingState();
    ~WorkerEatingState(){};

    // StateWorker interface
public:
    std::unique_ptr<State> Action(Ant &ant);
};

#endif // EATINGSTATE_H
