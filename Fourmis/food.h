#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include "ground.h"

class Food : public Ground
{
public:
    Food();
    Food(int _x, int _y);
    ~Food();
    int decrease_quantity(int amount);
    virtual int getType();
    int get_quantity_food();
private:
    int quantity;
};

#endif // FOOD_H
