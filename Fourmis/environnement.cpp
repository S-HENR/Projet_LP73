#include "dirt.h"
#include "environnement.h"
#include "ground.h"

#include <iostream>
#include <ostream>

Environnement::Environnement()
{
    generate_ground();
}

Environnement::~Environnement()
{

}

void Environnement::generate_ground()
{
    for(std::size_t i = 0; i < myMap.size(); i++)
    {
      auto& row = myMap[i];
      for(std::size_t j = 0; j < row.size(); j++)
      {
        row[j] = std::make_unique<Dirt>();
      }
    }
}

void Environnement::display_ground()
{

}
