#ifndef ANTHILL_H
#define ANTHILL_H
#include <iostream>
#include <vector>
#include "ant.h"
#include "ground.h"

class Anthill : public Ground
{
public:
    Anthill();
    Anthill(int _max_ants_nb, int _max_quantity_food_stock);
    ~Anthill();
    virtual void getValue();
    virtual int getType();
private:
    int coordinates[2];
    int max_ants_nb;
    int quantity_food_stock;
    int max_quantity_food_stock;
    std::vector<std::shared_ptr<Ant>> ants;
};

#endif // ANTHILL_H
