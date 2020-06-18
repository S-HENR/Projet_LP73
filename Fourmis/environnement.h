#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H
#include <vector>
#include <array>
#include <memory>
#include <ctime>
#include "ground.h"
#include "dirt.h"
#include "obstacle.h"
#include "food.h"
#include "anthill.h"
#include "map_display.h"
#include "parameters.h"


class Environnement
{
public:
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
    void display_updated_ground(int x, int y);
private:
    int size[2];
    int food_number = 500;
    int obstacle_number = 1000;
    float pheromone_disappearance_rate = 0.95;
    std::vector<std::vector<Ground*>> board;
    Map_display map;
    void generate_anthill(int x, int y, Parameters& parameters);
    void generate_obstacle();
    void template_obstacle(int x, int y);
    void generate_food();
    void generate_dirt();
};

#endif // ENVIRONNEMENT_H
