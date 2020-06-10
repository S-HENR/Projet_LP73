#ifndef FULL_GROWN_ANT_H
#define FULL_GROWN_ANT_H
#include "ant.h"

class FullGrownAnt : public Ant
{
public:
    FullGrownAnt();
    ~FullGrownAnt();
    virtual void movement() = 0;

    // Ant interface
public:
    virtual int increase_food_need() = 0;
    virtual void eat() = 0;

private :
    int carrying_capacity;
};

#endif // FULL_GROWN_ANT_H
