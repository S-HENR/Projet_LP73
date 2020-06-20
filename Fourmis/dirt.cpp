#include "dirt.h"


Dirt::Dirt() : Ground(true), pheromone_rate(0)
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
