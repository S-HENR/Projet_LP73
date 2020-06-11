#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

#include "ground.h"

#include <array>
#include <memory>


class Environnement
{
public:
    Environnement();
    ~Environnement();
    void generate_ground();
    void display_ground();

private :
    std::array<std::array<std::unique_ptr<Ground>, 50>, 100> myMap;
};

#endif // ENVIRONNEMENT_H
