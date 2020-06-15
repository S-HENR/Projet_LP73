#ifndef IDLELARVA_H
#define IDLELARVA_H

#include "state.h"



class IdleLarva : public State
{
public:
    IdleLarva();
    ~IdleLarva(){};

    // StateLarva interface
public:
    std::unique_ptr<State> Action(Ant &ant) override;
};

#endif // IDLELARVA_H

