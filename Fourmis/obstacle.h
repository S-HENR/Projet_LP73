#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <iostream>
#include "ground.h"

class Obstacle : public Ground
{
public:
    Obstacle();
    Obstacle(int _x, int _y);
    ~Obstacle();
    virtual int getType();
};

#endif // OBSTACLE_H
