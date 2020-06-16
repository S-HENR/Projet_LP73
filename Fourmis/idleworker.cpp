#include "idleworker.h"
#include "worker.h"

IdleWorker::IdleWorker()
{

}

std::unique_ptr<State> IdleWorker::Action(Ant& ant)
{
    Worker& worker = dynamic_cast<Worker&>(ant);







//    const int range_from  = 0;
//    const int range_to    = 49;
//    std::random_device rand_dev;
//    std::mt19937 generator(rand_dev());
//    std::uniform_int_distribution<int> distr(range_from, range_to);

//    if( queen.get_max_food_need() - queen.get_food_need() <= 10 )
//    {
//        queen.set_is_hungry(true);
//    }
//    else if(distr(generator) == 0)
//    {
//        return std::make_unique<LayingAnEggState>();
//    }
//    queen.increase_food_need();

//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
    return nullptr;
}
