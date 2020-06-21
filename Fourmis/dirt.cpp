#include "dirt.h"


Dirt::Dirt(int _x, int _y) :
    Ground(true, _x, _y),
    pheromone_rate(0)
{

}

Dirt::~Dirt()
{

}

void Dirt::apply_disappearance_rate()
{

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
