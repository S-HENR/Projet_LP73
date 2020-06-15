#include "food.h"

Food::Food(): Ground(false)
{
    //random de 8 à 12 à affecter à quantity?
    quantity = rand() % 13 + 7;
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

void Food::getValue()
{
    std::cout << "F";
}

int Food::getType()
{
    return 3;
}

int Food::get_quantity_food()
{
    return quantity;
}
