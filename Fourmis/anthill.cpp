#include "anthill.h"
#include "egg.h"
#include "larva.h"
#include "queen.h"
#include "warrior.h"
#include "worker.h"
#include <ostream>

Anthill::Anthill() : Ground(true)
{
    generate_ants();
}

Anthill::Anthill(int _max_ants_nb, int _max_quantity_food_stock) : Ground(true), max_ants_nb(_max_ants_nb), max_quantity_food_stock(_max_quantity_food_stock)
{

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

void Anthill::generate_ants()
{
    //temp liste of ants for tests
        for(int i = 0; i < 5; i++)
        {
            auto e = std::make_shared<Egg>(this, false);
            ants.emplace_back(e);
        }
        for(int i = 0; i < 7; i++)
        {
            auto l = std::make_shared<Larva>(this, false);
            ants.emplace_back(l);
        }
        for(int i = 0; i < 10; i++)
        {
            auto wk = std::make_shared<Worker>(this, false);
            ants.emplace_back(wk);
        }
        for(int i = 0; i < 10; i++)
        {
            auto wr = std::make_shared<Warrior>(this, false);
            ants.emplace_back(wr);
        }
        auto q = std::make_shared<Queen>(this, false);
        ants.emplace_back(q);
}

std::vector<std::shared_ptr<Ant> > Anthill::get_ants() const
{
    return ants;
}

void Anthill::set_ants(const std::vector<std::shared_ptr<Ant> > &value)
{
    ants = value;
}
