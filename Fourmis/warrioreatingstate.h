#ifndef WARRIOREATINGSTATE_H
#define WARRIOREATINGSTATE_H

#include "state.h"



class WarriorEatingState : public State
{
public:
    WarriorEatingState();
    ~WarriorEatingState(){};

    // StateWorker interface
public:
    std::unique_ptr<State> Action(Ant& ant);
};

#endif // WARRIOREATINGSTATE_H
