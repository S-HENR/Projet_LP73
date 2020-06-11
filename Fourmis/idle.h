#ifndef IDLE_H
#define IDLE_H

#include "ant.h"
#include "state.h"
#include <memory>


class Idle : public State
{
public:
    Idle();
    ~Idle();

    virtual std::unique_ptr<State> Action(Ant& ant) override;
};

#endif // IDLE_H

