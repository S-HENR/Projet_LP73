#ifndef DEPENDENTANT_H
#define DEPENDENTANT_H

#include "ant.h"



class DependentAnt : public Ant
{
public:
    DependentAnt() = delete;
    DependentAnt(Environnement& _env, Anthill* _anthill, bool _is_queen = false, int _food_need = 0, int _max_food_need = 0, int _time_to_transition = 10, bool _is_being_fed = false);
    ~DependentAnt();

    // Ant interface
public:
    virtual void increase_food_need() = 0;
    virtual void eat() = 0;

    bool get_is_being_fed() const;
    void set_is_being_fed(bool value);

private:
    bool is_being_fed;
};

#endif // DEPENDENTANT_H
