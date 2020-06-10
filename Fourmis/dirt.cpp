#include "dirt.h"


Dirt::Dirt(int coordinateX, int coordinateY, float ph_rate) : Ground(coordinateX, coordinateY, true), pheromone_rate(ph_rate)
{

}

Dirt::~Dirt()
{

}

void Dirt::apply_disappearance_rate()
{

}

void Dirt::getValue()
{
    std::cout << getCrossable() << std::endl;
}
