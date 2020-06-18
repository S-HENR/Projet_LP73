#ifndef WARRIOR_H
#define WARRIOR_H

#include "ant.h"


class Warrior : public Ant
{
public:
    Warrior();
    Warrior(Environnement* _env, Anthill* _anthill, bool _is_queen = false, int _food_need = 0, int _max_food_need = 0, int _time_to_transition = 10);
    ~Warrior();
    void movement();
    void lay_pheromone();

    int get_carrying_capacity() const;
    void set_carrying_capacity(int value);

    int get_quantity_carried() const;
    void set_quantity_carried(int value);

    // Ant interface
public:
    void increase_food_need();
    void eat();

private :
    int carrying_capacity;
    int quantity_carried;
};

#endif // WARRIOR_H
