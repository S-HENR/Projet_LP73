#include "feedingstate.h"
#include "ant.h"
#include "worker.h"

FeedingState::FeedingState()
{

}

std::unique_ptr<State> FeedingState::Action(Ant& ant)
{
    Worker& worker = dynamic_cast<Worker&>(ant);

//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
    return nullptr;
}

