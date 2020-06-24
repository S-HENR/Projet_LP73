#ifndef QUEEN_H
#define QUEEN_H
#include "dependentant.h"

class Queen : public DependentAnt
{
public:
    Queen() = delete;
    Queen(Environnement& _env, Anthill* _anthill, bool _is_queen = false, int _max_food_need = 0, int _time_to_transition = 10, float _food_need = 0, bool _is_being_fed = false);
    ~Queen();

    // Ant interface
public:
    virtual void increase_food_need();
    virtual void eat();
    virtual int getType();
};

#endif // QUEEN_H
