#include "anthill.h"
#include "egg.h"
#include "larva.h"
#include "queen.h"
#include "warrior.h"
#include "worker.h"

Anthill::Anthill(Environnement env, int x, int y, Parameters& parameters) :
    Ground(true),
    coordinates({x,y}),
    max_ants_nb(parameters.nb_max_ants),
    max_quantity_food_stock(parameters.nb_max_food),
    m_env(env)
{
    generate_ants(env, parameters.nb_init_workers, parameters.nb_init_warriors);
}

Anthill::~Anthill()
{

}

void Anthill::getValue()
{
    std::cout << "X";
}

int Anthill::getType()
{
    return 0;
}

void Anthill::generate_ants(Environnement& env, int nb_workers, int nb_warriors)
{
    //temp liste of ants for tests

    //std::cout << nb_workers << " - " << nb_warriors << " - " << env->getSizeX();
    // for(int i = 0; i < 5; i++)
    // {
    //     auto e = std::make_shared<Egg>(this, false);
    //     ants.emplace_back(e);
    // }
//     for(int i = 0; i < 7; i++)
//     {
//         auto l = std::make_shared<Larva>(env, this, false);
//         ants.emplace_back(l);
//     }
    for(int i = 0; i < nb_workers; i++)
    {
        auto wk = std::make_shared<Worker>(env, this, false);
        ants.emplace_back(wk);
    }
    for(int i = 0; i < nb_warriors; i++)
    {
        auto wr = std::make_shared<Warrior>(env, this, false);
        ants.emplace_back(wr);
    }
    auto q = std::make_shared<Queen>(env, this, false);
    ants.emplace_back(q);
}

int Anthill::queens_counter()
{
    int queens_nb = 0;

    for(auto&& ant: this->ants)
    {
        if( std::dynamic_pointer_cast<Queen>(ant) != nullptr)
        {
            queens_nb++;
        }
    }
    return queens_nb;
}

std::vector<std::shared_ptr<Ant> > Anthill::get_ants() const
{
    return ants;
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

void Anthill::set_quantity_food_stock(int value)
{
    quantity_food_stock = value;
}

std::array<int, 2> Anthill::get_coordinates() const
{
    return coordinates;
}

void Anthill::set_coordinates(const std::array<int, 2> &value)
{
    coordinates = value;
}
