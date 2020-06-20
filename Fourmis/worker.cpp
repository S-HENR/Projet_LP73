#include "idleworker.h"
#include "worker.h"

Worker::Worker(Environnement& _env, Anthill* _anthill, bool _is_queen, int _food_need, int _max_food_need, int _time_to_transition) :
    Ant(_env, _anthill, _is_queen, _food_need, _max_food_need, _time_to_transition, std::make_unique<IdleWorker>())
{

}

Worker::~Worker()
{

}

void Worker::increase_food_need()
{
    set_food_need(get_food_need() + 1 );
}

void Worker::eat()
{

}
