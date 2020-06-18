#ifndef FEEDINGSTATE_H
#define FEEDINGSTATE_H

#include "dependentant.h"
#include "state.h"



class FeedingState : public State
{
public:
    FeedingState();
    FeedingState(std::shared_ptr<DependentAnt> depAnt);
    ~FeedingState(){};

    // State interface
public:
    std::unique_ptr<State> Action(Ant &ant);

private:
    std::shared_ptr<DependentAnt> hungry_ant;
};

#endif // FEEDINGSTATE_H
