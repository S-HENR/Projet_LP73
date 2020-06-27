#include "workereatingstate.h"
#include "ant.h"
#include "worker.h"
#include "idleworker.h"

WorkerEatingState::WorkerEatingState()
{

}

std::unique_ptr<State> WorkerEatingState::Action(Ant& ant)
{
    Worker& worker = dynamic_cast<Worker&>(ant);

    worker.increase_food_need();

    if(worker.get_anthill()->get_quantity_food_stock() > 0)
    {
        if(worker.get_anthill()->get_quantity_food_stock() >= worker.get_food_need())
        {
            //if the anthill has enough food stock to fully satisfy the ant's needs
            worker.decrease_food_need(worker.get_food_need());
            worker.get_anthill()->decrease_quantity_food_stock(worker.get_food_need());
        }
        else
        {
            //if the anthill has not enough food stock to fully satisfy the ant's needs
            worker.get_anthill()->decrease_quantity_food_stock(worker.get_anthill()->get_quantity_food_stock());
            worker.decrease_food_need(worker.get_anthill()->get_quantity_food_stock());
        }
    }

    return std::make_unique<IdleWorker>();
}
