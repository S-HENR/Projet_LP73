#ifndef ANTHILL_H
#define ANTHILL_H
#include <iostream>
#include <vector>
#include <memory>
#include <array>
#include "ground.h"
#include "environnement.h"

class Ant;
class Parameters;
class Environnement;

class Anthill : public Ground
{
public:
    Anthill(Environnement& env, Parameters& parameters, int _x, int _y);
    ~Anthill();
    virtual int getType();
    void generate_ants(Environnement& env, int nb_workers, int nb_warriors, int food_need, int time_to_trans, int carrying_cap);
    int queens_counter();

    std::vector<std::shared_ptr<Ant>> get_ants(); // const; pour la supp des fourmis ??
    int get_nb_ant_type(int type);
    void set_ants(const std::vector<std::shared_ptr<Ant>> &value);

    int get_max_ants_nb() const;
    void set_max_ants_nb(int value);

    int get_quantity_food_stock() const;
    void increase_quantity_food_stock(int value);
    void decrease_quantity_food_stock(int value);

    int get_max_quantity_food_stock() const;
    void set_max_quantity_food_stock(int value);

private:
    int max_ants_nb;
    int quantity_food_stock;
    int max_quantity_food_stock;
    std::vector<std::shared_ptr<Ant>> ants;
};

#endif // ANTHILL_H
