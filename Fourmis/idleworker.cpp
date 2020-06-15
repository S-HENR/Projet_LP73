#include "idleworker.h"
#include "worker.h"

IdleWorker::IdleWorker()
{

}

std::unique_ptr<State> IdleWorker::Action(Ant& ant)
{
    Worker& worker = dynamic_cast<Worker&>(ant);

//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
    return nullptr;
}
