#include "food.h"


Food::Food(int _x, int _y) :
    Ground(true, _x, _y),
    generator((std::random_device())())
{
    //Generates the food block with an amount of food between 10 and 20 units
    std::uniform_int_distribution<int> distr(10, 20);
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
