#include "anthill.h"
#include "egg.h"
#include "larva.h"
#include "queen.h"
#include "warrior.h"
#include "worker.h"
#include <ostream>

//cf si peux init dans liste meme si deja liste classe mere
Anthill::Anthill() : Ground(true)
{
    //temp liste of ants for tests
    for(int i = 0; i < 5; i++)
    {
        auto e = std::make_shared<Egg>(false);
        this->ants.push_back(e);
    }
    for(int i = 0; i < 7; i++)
    {
        auto l = std::make_shared<Larva>(false);
        ants.push_back(l);
    }
    for(int i = 0; i < 10; i++)
    {
        auto wk = std::make_shared<Worker>(false);
        ants.push_back(wk);
    }
    for(int i = 0; i < 10; i++)
    {
        auto wr = std::make_shared<Warrior>(false);
        ants.push_back(wr);
    }
    auto q = std::make_shared<Queen>(false);
    ants.push_back(q);

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
