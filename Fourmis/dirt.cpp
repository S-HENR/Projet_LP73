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

void Dirt::getValue()
{
    std::cout << "O";
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
