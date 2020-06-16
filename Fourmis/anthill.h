#ifndef ANTHILL_H
#define ANTHILL_H
#include <iostream>
#include <vector>
#include <memory>
#include "ground.h"

class Ant;

class Anthill : public Ground
{
public:
    Anthill();
    Anthill(int _max_ants_nb, int _max_quantity_food_stock);
    ~Anthill();
    virtual void getValue();
    virtual int getType();
    void generate_ants();
    std::vector<std::shared_ptr<Ant>> get_ants() const;
    void set_ants(const std::vector<std::shared_ptr<Ant>> &value);

private:
    int coordinates[2];
    int max_ants_nb;
    int quantity_food_stock;
    int max_quantity_food_stock;
    std::vector<std::shared_ptr<Ant>> ants;
};

#endif // ANTHILL_H
