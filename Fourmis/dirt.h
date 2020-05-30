#ifndef DIRT_H
#define DIRT_H
#include "ground.h"

class Dirt : public Ground
{
public:
    Dirt();
    ~Dirt();
    void apply_disappearance_rate();
private:
    float pheromone_rate;
};

#endif // DIRT_H
