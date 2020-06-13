#ifndef STATE_H
#define STATE_H

#include <memory>

class Ant;

class State
{
public:
    State(){}
    ~State(){}
    virtual std::unique_ptr<State> Action(Ant& ant) = 0;
};

#endif // STATE_H
