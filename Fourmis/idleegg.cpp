#include "egg.h"
#include "idleegg.h"

IdleEgg::IdleEgg()
{

}

std::unique_ptr<State> IdleEgg::Action(Ant& ant)
{
    Egg& egg = dynamic_cast<Egg&>(ant);

    return nullptr;
}
