#ifndef IDLEWORKER_H
#define IDLEWORKER_H

#include "state.h"



class IdleWorker : public State
{
public:
    IdleWorker();
    ~IdleWorker(){};

    // StateWorker interface
public:
    std::unique_ptr<State> Action(Ant &ant);
};

#endif // IDLEWORKER_H
