#ifndef LARVA_H
#define LARVA_H

#include "dependentant.h"

class Larva : public DependentAnt
{
public:
    Larva() = delete;
    Larva(Environnement& _env, Anthill* _anthill, bool _is_queen = false, int _max_food_need = 0, int _time_to_transition = 10, int _food_need = 0, bool _is_being_fed = false);
    ~Larva();

    // Ant interface
public:
    virtual void increase_food_need();
    virtual void eat();
    virtual int getType();
};

#endif // LARVA_H
