#ifndef WORKER_H
#define WORKER_H

#include "ant.h"


class Worker : public Ant
{
public:
    Worker();
    Worker(bool _is_queen = false, int _food_need = 0, int _max_food_need = 0, int _time_to_transition = 10);
    ~Worker();

    // Ant interface
public:
    void increase_food_need();
    void eat();
};

#endif // WORKER_H
