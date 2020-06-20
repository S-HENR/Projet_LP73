#ifndef LARVA_H
#define LARVA_H

#include "dependentant.h"

class Larva : public DependentAnt
{
public:
    Larva() = delete;
    Larva(Environnement& _env, Anthill* _anthill, bool _is_queen = false, int _food_need = 0, int _max_food_need = 0, int _time_to_transition = 10, bool _is_being_fed = false);
    ~Larva();

    // Ant interface
public:
    void increase_food_need();
    void eat();
};

#endif // LARVA_H
