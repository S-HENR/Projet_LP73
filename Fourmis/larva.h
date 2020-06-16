#ifndef LARVA_H
#define LARVA_H

#include "ant.h"

class Larva : public Ant
{
public:
    Larva();
    Larva(bool _is_queen = false, int _food_need = 0, int _max_food_need = 0, int _time_to_transition = 10);
    ~Larva();

    bool get_is_hungry() const;
    void set_is_hungry(bool value);

    // Ant interface
public:
    void increase_food_need();
    void eat();

private:
    bool is_hungry = false;

};
    
#endif // LARVA_H
