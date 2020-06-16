#ifndef EGG_H
#define EGG_H

#include "ant.h"



class Egg : public Ant
{
public:
    Egg();
    Egg(Anthill* _anthill, bool _is_queen = false, int _food_need = 0, int _max_food_need = 0, int _time_to_transition = 10);
    ~Egg();

    // Ant interface
public:
    void increase_food_need();
    void eat();
};

#endif // EGG_H
