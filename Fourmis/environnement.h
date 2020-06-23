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
#include "map_display.h"
#include "parameters.h"

class Anthill;

class Environnement
{
public:
    Environnement(int height = 100,int length = 50, int obstacle = 1000, int food = 500, float _pheromone_rate = 0.95);
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

    Anthill *get_anthill() const;
    void set_anthill(Anthill *value);

    Map_display get_map() const;

    std::vector<std::vector<Ground *> > get_board() const;

private:
    int size[2];
    int food_number;
    int obstacle_number;
    float pheromone_disappearance_rate;
    Anthill* anthill;
    std::vector<std::vector<Ground*>> board;
    Map_display map;
    void generate_anthill(int x, int y, Parameters& parameters);
    void generate_obstacle();
    void template_obstacle(int x, int y);
    void generate_food();
    void generate_dirt();
};

#endif // ENVIRONNEMENT_H
