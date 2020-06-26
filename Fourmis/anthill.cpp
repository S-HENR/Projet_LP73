#include "anthill.h"
#include "egg.h"
#include "larva.h"
#include "queen.h"
#include "warrior.h"
#include "worker.h"

Anthill::Anthill(Environnement& env, Parameters& parameters, int _x, int _y) :
    Ground(true, _x, _y),
    max_ants_nb(parameters.nb_max_ants),
    quantity_food_stock(0),
    max_quantity_food_stock(parameters.nb_max_food)

{
    generate_ants(env, parameters.nb_init_larvas, parameters.nb_init_workers, parameters.nb_init_warriors, parameters.amount_food_need, parameters.time_to_transition, parameters.carrying_capacity);
}

Anthill::~Anthill()
{

}

int Anthill::getType()
{
    return 0;
}

void Anthill::generate_ants(Environnement& env, int nb_larvas, int nb_workers, int nb_warriors, int food_need, int time_to_trans, int carrying_cap)
{
    //temp liste of ants for tests

    //std::cout << nb_workers << " - " << nb_warriors << " - " << env->getSizeX();
    // for(int i = 0; i < 5; i++)
    // {
    //     auto e = std::make_shared<Egg>(this, false);
    //     ants.emplace_back(e);
    // }

    if((nb_larvas + nb_workers + nb_warriors + 1) < max_ants_nb)
    {
        for(int i = 0; i < nb_larvas; i++)
        {
            auto l = std::make_shared<Larva>(env, this, false, food_need, time_to_trans);
            ants.emplace_back(l);
        }
        for(int i = 0; i < nb_workers; i++)
        {
            auto wk = std::make_shared<Worker>(env, this, false, food_need, time_to_trans);
            ants.emplace_back(wk);
        }
        for(int i = 0; i < nb_warriors; i++)
        {
            auto wr = std::make_shared<Warrior>(env, this, false, food_need, time_to_trans, carrying_cap);
            ants.emplace_back(wr);
        }
        auto q = std::make_shared<Queen>(env, this, true, food_need, time_to_trans);
        ants.emplace_back(q);
    }
    else
    {
        std::cout << "Nombre de fourmis intialisé supérieur au nombre maximum de fourmis";
    }
}

int Anthill::queens_counter()
{
    int queens_nb = 0;

    for(auto& ant: ants)
    {
        if( std::dynamic_pointer_cast<Queen>(ant) != nullptr)
        {
            queens_nb++;
        }
    }
    return queens_nb;
}

std::vector<std::shared_ptr<Ant>>& Anthill::get_ants()
{
    return ants;
}

int Anthill::get_nb_ant_type(int type)
{
    int size = ants.size();
    int counter = 0;
    for(int i = 0 ; i < size ; i++)
    {
        if(ants[i]->getType() == type)
            counter++;
    }
    return counter;
}

void Anthill::set_ants(const std::vector<std::shared_ptr<Ant> > &value)
{
    ants = value;
}

int Anthill::get_max_ants_nb() const
{
    return max_ants_nb;
}

void Anthill::set_max_ants_nb(int value)
{
    max_ants_nb = value;
}

int Anthill::get_quantity_food_stock() const
{
    return quantity_food_stock;
}

void Anthill::increase_quantity_food_stock(int value)
{
    quantity_food_stock += value;
}

void Anthill::decrease_quantity_food_stock(int value)
{
    quantity_food_stock -= value;
}

int Anthill::get_max_quantity_food_stock() const
{
    return max_quantity_food_stock;
}

void Anthill::set_max_quantity_food_stock(int value)
{
    max_quantity_food_stock = value;
}
