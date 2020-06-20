#include "obstacle.h"


Obstacle::Obstacle() : Ground(false)
{

}

Obstacle::~Obstacle()
{

}

int Obstacle::getType()
{
    return 2;
}
