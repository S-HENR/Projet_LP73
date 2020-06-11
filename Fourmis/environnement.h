#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H
#include <vector>
#include <array>
#include <memory>
#include "ground.h"

class Environnement
{
public:
    Environnement(int height,int length, int food, int obstacle);
    ~Environnement();
    void generate_ground();
    void display_ground();
private:
    int size[2];
    int food_number;
    int obstacle_number;
    std::vector<std::vector<Ground*>> board;
};

#endif // ENVIRONNEMENT_H
