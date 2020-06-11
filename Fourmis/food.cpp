#include "food.h"

Food::Food(): Ground(false)
{
    //random de 8 à 12 à affecter à quantity?
    quantity = rand() % 13 + 7;
}

Food::~Food()
{

}

void Food::decrease_quantity(int amount)
{

}

void Food::getValue()
{
    std::cout << "F";
}
