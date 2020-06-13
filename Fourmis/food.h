#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include "ground.h"

class Food : public Ground
{
public:
    Food();
    ~Food();
    void decrease_quantity(int amount);
    virtual void getValue();
    virtual int getType();
    int get_quantity_food();
private:
    int quantity;
};

#endif // FOOD_H
