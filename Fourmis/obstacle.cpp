#include "obstacle.h"


Obstacle::Obstacle() : Ground(false)
{

}

Obstacle::~Obstacle()
{

}

void Obstacle::getValue()
{
    std::cout << "#";
}

int Obstacle::getType()
{
    return 2;
}
