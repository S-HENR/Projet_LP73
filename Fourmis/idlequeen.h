#ifndef IDLEQUEEN_H
#define IDLEQUEEN_H

#include "state.h"



class IdleQueen : public State
{
public:
    IdleQueen();
    ~IdleQueen(){};

    // StateQueen interface
public:
    std::unique_ptr<State> Action(Ant &ant);
};

#endif // IDLEQUEEN_H
