#ifndef WORKER_H
#define WORKER_H

#include "ant.h"


class Worker : public Ant
{
public:
    Worker() = delete;
    Worker(Environnement& _env, Anthill* _anthill, bool _is_queen = false, int _max_food_need = 0, int _time_to_transition = 10, float _food_need = 0);
    ~Worker();

    // Ant interface
public:
    virtual void increase_food_need();
    virtual void eat();
    virtual int getType();
};

#endif // WORKER_H
