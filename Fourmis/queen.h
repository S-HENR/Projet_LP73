#ifndef QUEEN_H
#define QUEEN_H
#include "ant.h"

class Queen : public Ant
{
public:
    Queen();
    ~Queen();

    // Ant interface
public:
    int increase_food_need();
    void eat();
};

#endif // QUEEN_H
