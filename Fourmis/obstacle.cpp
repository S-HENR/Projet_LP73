#include "obstacle.h"


Obstacle::Obstacle(int coordinateX, int coordinateY) : Ground(coordinateX, coordinateY, false)
{

}

Obstacle::~Obstacle()
{

}

void Obstacle::getValue()
{
    std::cout << getCrossable() << std::endl;
}
