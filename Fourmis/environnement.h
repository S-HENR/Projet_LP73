#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H
#include <vector>
#include <array>
#include <memory>
#include "ground.h"

class Environnement
{
public:
    Environnement(int lon, int lar);
    ~Environnement();
    void generate_ground();
    void display_ground();
private:
    int size[2];
    std::vector<std::vector<Ground*>> board;
};

#endif // ENVIRONNEMENT_H
