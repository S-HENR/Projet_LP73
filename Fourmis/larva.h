#ifndef LARVA_H
#define LARVA_H
#include "ant.h"

class Larva : public Ant
{
public:
    Larva();
    ~Larva();

    // Ant interface
public:
    int increase_food_need();
    void eat();
};

#endif // LARVA_H
