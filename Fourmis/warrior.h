#ifndef WARRIOR_H
#define WARRIOR_H

#include "ant.h"


class Warrior : public Ant
{
public:
    Warrior();
    Warrior(Anthill* _anthill, bool _is_queen = false, int _food_need = 0, int _max_food_need = 0, int _time_to_transition = 10);
    ~Warrior();
    void movement();
    void lay_pheromone();

    // Ant interface
public:
    void increase_food_need();
    void eat();

private :
    int carrying_capacity;
};

#endif // WARRIOR_H
