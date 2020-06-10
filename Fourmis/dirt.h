#ifndef DIRT_H
#define DIRT_H
#include <iostream>
#include "ground.h"

class Dirt : public Ground
{
    public:
        Dirt(int coordinateX, int coordinateY, float ph_rate);
        ~Dirt();
        void apply_disappearance_rate();
        virtual void getValue();
    private:
        float pheromone_rate;
};

#endif // DIRT_H
