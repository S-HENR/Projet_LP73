#ifndef LAYINGANEGGSTATE_H
#define LAYINGANEGGSTATE_H

#include "state.h"



class LayingAnEggState : public State
{
public:
    LayingAnEggState();
    ~LayingAnEggState(){};

    // State interface
public:
    std::unique_ptr<State> Action(Ant &ant);
};

#endif // LAYINGANEGGSTATE_H
