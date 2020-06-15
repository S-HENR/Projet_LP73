#ifndef FEEDINGSTATE_H
#define FEEDINGSTATE_H

#include "state.h"



class FeedingState : public State
{
public:
    FeedingState();
    ~FeedingState(){};

    // State interface
public:
    std::unique_ptr<State> Action(Ant &ant);
};

#endif // FEEDINGSTATE_H
