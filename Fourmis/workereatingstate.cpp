#include "workereatingstate.h"
#include "ant.h"
#include "worker.h"

WorkerEatingState::WorkerEatingState()
{

}

std::unique_ptr<State> WorkerEatingState::Action(Ant& ant)
{
    Worker& worker = dynamic_cast<Worker&>(ant);

//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
    return nullptr;
}
