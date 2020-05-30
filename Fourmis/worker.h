#ifndef WORKER_H
#define WORKER_H
#include "fullgrownant.h"

class Worker : public FullGrownAnt
{
public:
    Worker();
    ~Worker();

    // Ant interface
public:
    int increase_food_need();
    void eat();

    // FullGrownAnt interface
public:
    void movement();
};

#endif // WORKER_H
