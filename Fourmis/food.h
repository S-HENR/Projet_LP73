#ifndef FOOD_H
#define FOOD_H
#include "ground.h"

class Food : public Ground
{
public:
    Food(int coordinateX, int coordinateY, bool crossable);
    ~Food();
    void decrease_quantity(int amount);
private:
    int quantity;
};

#endif // FOOD_H
