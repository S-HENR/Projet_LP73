#include "idleworker.h"
#include "worker.h"

Worker::Worker(Environnement& _env, Anthill* _anthill, bool _is_queen, int _max_food_need, int _time_to_transition, int _food_need) :
    Ant(_env, _anthill, _is_queen, _max_food_need, _time_to_transition,_food_need, std::make_unique<IdleWorker>())
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
