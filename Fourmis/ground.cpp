#include "ground.h"

Ground::Ground(int coordinateX, int coordinateY, bool crossable)
{
    coordinates[0] = coordinateX;
    coordinates[1] = coordinateY;
    this->crossable = crossable;
}

Ground::~Ground()
{

}

int Ground::getCoordinateX()
{
    return coordinates[0];
}

int Ground::getCoordinateY()
{
    return coordinates[1];
}

bool Ground::getCrossable()
{
    return crossable;
}
