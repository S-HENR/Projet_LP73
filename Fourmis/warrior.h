#ifndef WARRIOR_H
#define WARRIOR_H
#include "fullgrownant.h"

class Warrior : public FullGrownAnt
{
public:
    Warrior();
    ~Warrior();

    // Ant interface
public:
    int increase_food_need();
    void eat();

    // FullGrownAnt interface
public:
    void movement();
};

#endif // WARRIOR_H
