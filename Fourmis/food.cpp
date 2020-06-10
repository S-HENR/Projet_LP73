#include "food.h"

Food::Food(int coordinateX, int coordinateY, bool crossable) : Ground(coordinateX, coordinateY, crossable)
{
    //random de 8 à 12 à affecter à quantity?
}

Food::~Food()
{

}

void Food::decrease_quantity(int amount)
{

}
