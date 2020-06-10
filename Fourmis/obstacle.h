#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <iostream>
#include "ground.h"

class Obstacle : public Ground
{
public:
    Obstacle(int coordinateX, int coordinateY);
    ~Obstacle();
    virtual void getValue();
};

#endif // OBSTACLE_H
