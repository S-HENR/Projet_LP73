#include "feedingstate.h"
#include "idleworker.h"
#include "larva.h"
#include "queen.h"
#include "worker.h"
#include "workereatingstate.h"
#include <string.h>

IdleWorker::IdleWorker()
{

}

std::unique_ptr<State> IdleWorker::Action(Ant& ant)
{
    Worker& worker = dynamic_cast<Worker&>(ant);

    worker.increase_food_need();
    //seeking for a dependantAnt in need of food
    for(auto& ant: worker.get_anthill()->get_ants())
    {
        if(ant->get_max_food_need() - ant->get_food_need() <= 5)
        {
            if(auto depAnt = std::dynamic_pointer_cast<DependentAnt>(ant))
            {
                if(depAnt->get_is_being_fed() == false)
                {
                    //if the depAnt (Larva or Queen) is hungry and is not already taking care of by another worker

                    depAnt->set_is_being_fed(true);
                    return std::make_unique<FeedingState>(depAnt);
                }
            }
        }
    }

    //if the worker is hungry
    if ((worker.get_max_food_need() - worker.get_food_need()) <= 5)
    {
        return std::make_unique<WorkerEatingState>();
    }

    //condition construction agrandissement
    return nullptr;
}
