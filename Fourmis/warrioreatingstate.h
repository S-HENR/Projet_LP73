#ifndef WARRIOREATINGSTATE_H
#define WARRIOREATINGSTATE_H

#include "food.h"
#include "state.h"



class WarriorEatingState : public State
{
public:
    WarriorEatingState() = delete;
    WarriorEatingState(Food& tile);
    ~WarriorEatingState(){};

    // StateWorker interface
public:
    std::unique_ptr<State> Action(Ant& ant);

private:
    Food&  food_tile;
};

#endif // WARRIOREATINGSTATE_H
