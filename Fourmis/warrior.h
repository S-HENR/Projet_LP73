#ifndef WARRIOR_H
#define WARRIOR_H

#include "ant.h"


class Warrior : public Ant
{
public:
    Warrior();
    Warrior(int _food_need = 0, int _max_food_need = 50, int _time_to_transition = 50, bool _is_queen = false);
    ~Warrior();
    void movement();
    void lay_pheromone();

    // Ant interface
public:
    int increase_food_need();
    void eat();

private :
    int carrying_capacity;
};

#endif // WARRIOR_H
