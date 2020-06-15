#ifndef IDLEWARRIOR_H
#define IDLEWARRIOR_H

#include "state.h"

class IdleWarrior : public State
{
public:
    IdleWarrior();
    ~IdleWarrior(){};

    // StateWarrior interface
public:
    std::unique_ptr<State> Action(Ant &ant);
};

#endif // IDLEWARRIOR_H
