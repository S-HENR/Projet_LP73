#ifndef GOINGBACKHOMESTATE_H
#define GOINGBACKHOMESTATE_H
#include <vector>
#include <array>
#include "state.h"
#include "ground.h"

class GoingBackHomeState : public State
{
public:
    GoingBackHomeState(std::array<int, 2> size, const std::vector<std::vector<Ground*>>& board, const coord& _coordinates_ant, const coord& _coordinates_anthill);
    ~GoingBackHomeState(){};
public:
    std::unique_ptr<State> Action(Ant &ant);
private:
    std::vector<std::vector<int>> steps;
    coord coordinates_ant;
    coord coordinates_anthill;
};

#endif // GOINGBACKHOMESTATE_H
