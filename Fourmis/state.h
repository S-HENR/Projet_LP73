#ifndef STATE_H
#define STATE_H

#include <memory>

class Ant;

class State
{
public:
    State();
    virtual ~State(){};
    virtual std::unique_ptr<State> Action(Ant& ant) = 0;
};

#endif // STATE_H
