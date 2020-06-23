#ifndef QUEEN_H
#define QUEEN_H
#include "dependentant.h"

class Queen : public DependentAnt
{
public:
    Queen() = delete;
    Queen(Environnement& _env, Anthill* _anthill, bool _is_queen = false, int _max_food_need = 0, int _time_to_transition = 10, int _food_need = 0, bool _is_being_fed = false);
    ~Queen();

    // Ant interface
public:
    void increase_food_need();
    void eat();
};

#endif // QUEEN_H
