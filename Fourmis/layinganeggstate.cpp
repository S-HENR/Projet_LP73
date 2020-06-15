#include "layinganeggstate.h"
#include "ant.h"
#include "queen.h"

LayingAnEggState::LayingAnEggState()
{

}

std::unique_ptr<State> LayingAnEggState::Action(Ant& ant)
{
    Queen& queen = dynamic_cast<Queen&>(ant);

//    if(false) // Une condition pr passer à un nouvelle état
//        return std::make_unique<UnAutreEtat>();
    return nullptr;
}
