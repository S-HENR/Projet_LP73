#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H
#include <vector>
#include <array>
#include <memory>
#include <ctime>
#include <random>
#include "ground.h"
#include "dirt.h"
#include "obstacle.h"
#include "food.h"
#include "map_display.h"
#include "parameters.h"

class Anthill;

class Environnement
{
public:
    Environnement(){};
    Environnement(int height,int length, int obstacle, int food);
    ~Environnement();
    void generate_ground(Parameters& parameter);
    void display_ground();
    Ground* getTile(int x,int y);
    int getSizeX();
    int getSizeY();
    int get_typeof_tile(int x, int y);
    int collect_food(int x, int y, int amount);
    void regenerate_food(int amount);

    Anthill *get_anthill() const;
    void set_anthill(Anthill *value);

    Map_display get_map() const;

    std::vector<std::vector<Ground *> > get_board() const;

    int generate_random(const int range_from, const int range_to);

private:
    int size[2];
    int food_number;
    int obstacle_number;
    Anthill* anthill;
    std::vector<std::vector<Ground*>> board;
    Map_display map;
    std::mt19937 generator;

    void generate_anthill(int x, int y, Parameters& parameters);
    void generate_obstacle();
    void template_obstacle(int x, int y);
    void generate_food();
    void generate_dirt();
};

#endif // ENVIRONNEMENT_H
