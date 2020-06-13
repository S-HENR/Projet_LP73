#include "ant.h"

Ant::Ant() :
    m_state(nullptr)
{
    //std::make_unique<Idle>();
}

Ant::~Ant()
{

}

int Ant::decrease_food_need()
{
    return 0;
}

void Ant::Action()
{
    //current_state.Action();
}

void Ant::FaireSonTraitement()
{
    auto newState = m_state->Action(*this);
    if(newState)
        m_state = std::move(newState);
}
