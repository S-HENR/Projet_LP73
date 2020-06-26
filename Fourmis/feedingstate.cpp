#include "feedingstate.h"
#include "ant.h"
#include "worker.h"
#include "idleworker.h"

FeedingState::FeedingState()
{

}

FeedingState::FeedingState(std::shared_ptr<DependentAnt> depAnt) : hungry_ant(depAnt)
{

}

std::unique_ptr<State> FeedingState::Action(Ant& ant)
{
    Worker& worker = dynamic_cast<Worker&>(ant);

    worker.increase_food_need();

    if(worker.get_anthill()->get_quantity_food_stock() > 0)
    {
        if(worker.get_anthill()->get_quantity_food_stock() >= hungry_ant->get_food_need())
        {
            //if the anthill has enough food stock to fully satisfy the ant's needs
            hungry_ant->decrease_food_need(hungry_ant->get_food_need());
            worker.get_anthill()->decrease_quantity_food_stock(hungry_ant->get_food_need());
        }
        else
        {
            //if the anthill has not enough food stock to fully satisfy the ant's needs
            hungry_ant->decrease_food_need(worker.get_anthill()->get_quantity_food_stock());
            worker.get_anthill()->decrease_quantity_food_stock(worker.get_anthill()->get_quantity_food_stock());
        }
    }

    hungry_ant->set_is_being_fed(false);
    return std::make_unique<IdleWorker>();

//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
}

