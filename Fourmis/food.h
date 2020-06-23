#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include <random>
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
    std::mt19937 generator;
};

#endif // FOOD_H
