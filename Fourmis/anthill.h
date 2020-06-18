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
    int queens_counter();

    std::vector<std::shared_ptr<Ant>> get_ants() const;
    void set_ants(const std::vector<std::shared_ptr<Ant>> &value);

    int get_max_ants_nb() const;
    void set_max_ants_nb(int value);

    int get_quantity_food_stock() const;
    void set_quantity_food_stock(int value);

private:
    int coordinates[2];
    int max_ants_nb;
    int quantity_food_stock;
    int max_quantity_food_stock;
    std::vector<std::shared_ptr<Ant>> ants;
};

#endif // ANTHILL_H
