#include "ground.h"

Ground::Ground( bool crossable) : crossable(crossable)
{

}

Ground::~Ground()
{

}

bool Ground::getCrossable()
{
    return crossable;
}
