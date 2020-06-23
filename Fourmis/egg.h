#ifndef EGG_H
#define EGG_H

#include "ant.h"



class Egg : public Ant
{
public:
    Egg() = delete;
    Egg(Environnement& _env, Anthill* _anthill, bool _is_queen = false, int _max_food_need = 0, int _time_to_transition = 10, int _food_need = 0);
    ~Egg();

    // Ant interface
public:
    void increase_food_need();
    void eat();
};

#endif // EGG_H
