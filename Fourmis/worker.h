#ifndef WORKER_H
#define WORKER_H

#include "ant.h"


class Worker : public Ant
{
public:
    Worker();
    Worker(int _food_need = 0, int _max_food_need = 50, int _time_to_transition = 50, bool _is_queen = false);
    ~Worker();

    // Ant interface
public:
    int increase_food_need();
    void eat();
};

#endif // WORKER_H
