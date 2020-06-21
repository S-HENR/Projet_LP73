#include "obstacle.h"


Obstacle::Obstacle(int _x, int _y) :
    Ground(false, _x, _y)
{

}

Obstacle::~Obstacle()
{

}

int Obstacle::getType()
{
    return 2;
}
