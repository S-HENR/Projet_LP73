#include "food.h"


Food::Food(int _x, int _y) :
    Ground(true, _x, _y),
    generator((std::random_device())())
{
    //random de 8 à 12 à affecter à quantity?
    //quantity = rand() % 13 + 7;

    std::uniform_int_distribution<int> distr(8, 12);
    int rand = distr(generator);

    quantity = rand;
}

Food::~Food()
{

}

int Food::decrease_quantity(int amount)
{
   if(amount < quantity)
       quantity -= amount;
   else
   {
       amount = quantity;
       quantity = 0;
   }
   return amount;
}


int Food::getType()
{
    return 3;
}

int Food::get_quantity_food()
{
    return quantity;
}
