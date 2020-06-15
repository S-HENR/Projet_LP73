#include "ant.h"
#include "movingstate.h"
#include "warrior.h"

MovingState::MovingState()
{

}

std::unique_ptr<State> MovingState::Action(Ant &ant)
{
    Warrior& warrior = dynamic_cast<Warrior&>(ant);
    //    if(false) // Une condition pr passer à un nouvelle état
    //        return std::make_unique<UnAutreEtat>();
        return nullptr;
}
