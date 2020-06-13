#ifndef MOVE_H
#define MOVE_H

#include "state.h"
#include <memory>


class Move : public State
{
public:
    Move();
    ~Move();

    // State interface
public:
    std::unique_ptr<State> Action(Ant &ant) override;
};

#endif // MOVE_H
