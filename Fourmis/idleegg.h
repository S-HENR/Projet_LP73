#ifndef IDLEEGG_H
#define IDLEEGG_H

#include "state.h"



class IdleEgg : public State
{
public:
    IdleEgg();
    ~IdleEgg(){};

    // StateLarva interface
public:
    std::unique_ptr<State> Action(Ant &ant) override;
};

#endif // IDLEEGG_H
