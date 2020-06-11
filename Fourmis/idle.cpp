#include "ant.h"
#include "idle.h"
#include <memory>

Idle::Idle()
{}

std::unique_ptr<State> Idle::Action(Ant& ant)
{
//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
    return nullptr;
}

