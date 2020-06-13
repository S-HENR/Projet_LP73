#ifndef IDLE_H
#define IDLE_H

#include "state.h"
#include <memory>


class Idle : public State
{
public:
    Idle();
    ~Idle();

    // State interface
public:
    std::unique_ptr<State> Action(Ant& ant) override;
};

#endif // IDLE_H

