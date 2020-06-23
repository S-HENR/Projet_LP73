#ifndef MOVINGSTATE_H
#define MOVINGSTATE_H

#include "ground.h"
#include "state.h"
#include "warrior.h"
#include <vector>

struct nearby_tiles
{
    Ground* tile;
    float prob;
};

class MovingState : public State
{
public:
    MovingState();
    ~MovingState(){};

    std::vector<nearby_tiles> get_nearby_tiles(Warrior* _warrior);

    // StateWarrior interface
public:
    std::unique_ptr<State> Action(Ant &ant) override;
};

#endif // MOVINGSTATE_H
