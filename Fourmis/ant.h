#ifndef ANT_H
#define ANT_H

#include <memory>

#include "state.h"

class Ant
{
public:
    Ant();
    ~Ant();
    int decrease_food_need();
    virtual int increase_food_need() = 0;
    virtual void eat() = 0;

    void Action();
    void FaireSonTraitement();

private:
    int coordinates[2];
    int food_need;
    int max_food_need;
    int time_to_transition;
    bool is_queen;

    std::unique_ptr<State> m_state = nullptr;
};

#endif // ANT_H
