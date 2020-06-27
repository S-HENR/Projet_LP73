#include "dirt.h"


Dirt::Dirt(int _x, int _y) :
    Ground(true, _x, _y),
    pheromone_rate(0)
{

}

Dirt::~Dirt()
{

}

int Dirt::apply_disappearance_rate(float pheromone_disappearance_rate)
{
    //pheromone rate set to 0 when < 1 to prevent very low rate e.g. 0.00001
    if(pheromone_rate < 1)
        pheromone_rate = 0;
    else
        pheromone_rate *= pheromone_disappearance_rate;
    return pheromone_rate;
}

int Dirt::getType()
{
    return 1;
}

float Dirt::get_pheromone_rate() const
{
    return pheromone_rate;
}

void Dirt::set_pheromone_rate(float value)
{
    pheromone_rate = value;
}
