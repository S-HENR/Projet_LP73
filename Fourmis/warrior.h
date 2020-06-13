#ifndef WARRIOR_H
#define WARRIOR_H

#include "ant.h"


class Warrior : public Ant
{
public:
    Warrior();
    ~Warrior();
    void movement();

    // Ant interface
public:
    int increase_food_need();
    void eat();

private :
    int carrying_capacity;
};

#endif // WARRIOR_H
