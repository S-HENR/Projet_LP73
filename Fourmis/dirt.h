#ifndef DIRT_H
#define DIRT_H
#include <iostream>
#include "ground.h"

class Dirt : public Ground
{
public:
    Dirt();
    Dirt(int _x, int _y);
    ~Dirt();
    int apply_disappearance_rate(float pheromone_disappearance_rate);
    virtual int getType();

    float get_pheromone_rate() const;
    void set_pheromone_rate(float value);

private:
    float pheromone_rate;
};

#endif // DIRT_H
