#include "ground.h"

Ground::Ground( bool crossable, int _x, int _y) :
    crossable(crossable),
    coordinates{.x = _x, .y = _y}
{

}

Ground::~Ground()
{

}

bool Ground::getCrossable()
{
    return crossable;
}

coord Ground::get_coordinates() const
{
    return coordinates;
}

void Ground::set_coordinates(const int &x, const int &y)
{
    coordinates.x = x;
    coordinates.y = y;
}
