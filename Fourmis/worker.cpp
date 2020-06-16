#include "worker.h"

Worker::Worker()
{

}

Worker::Worker(Anthill* _anthill, bool _is_queen, int _food_need, int _max_food_need, int _time_to_transition) :
    Ant(_anthill, _is_queen, _food_need, _max_food_need, _time_to_transition)
{

}

Worker::~Worker()
{

}

void Worker::increase_food_need()
{

}

void Worker::eat()
{

}
