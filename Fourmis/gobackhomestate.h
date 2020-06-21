#ifndef GOBACKHOMESTATE_H
#define GOBACKHOMESTATE_H
#include <vector>
#include <array>
#include "state.h"
#include "ground.h"

class GoBackHomeState : public State
{
public:
    GoBackHomeState(std::array<int, 2> size, std::vector<std::vector<Ground*>> board, coord& _coordinates_ant, coord& _coordinates_anthill);
    ~GoBackHomeState(){};
public:
    std::unique_ptr<State> Action(Ant &ant);
private:
    std::vector<std::vector<int>> steps;
    coord coordinates_ant;
    coord coordinates_anthill;
};

#endif // GOBACKHOMESTATE_H
