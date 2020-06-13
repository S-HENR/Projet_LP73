#ifndef WORKER_H
#define WORKER_H

#include "ant.h"


class Worker : public Ant
{
public:
    Worker();
    ~Worker();

    // Ant interface
public:
    int increase_food_need();
    void eat();
};

#endif // WORKER_H
