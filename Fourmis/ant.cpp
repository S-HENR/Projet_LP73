#include "ant.h"

Ant::Ant():
    m_state(nullptr)
{
    //std::make_unique<Idle>();
}

Ant::Ant(Anthill* _anthill, bool _is_queen, int _food_need, int _max_food_need, int _time_to_transition) :
    is_queen(_is_queen),
    food_need(_food_need),
    max_food_need(_max_food_need),
    time_to_transition(_time_to_transition),
    m_state(nullptr),
    m_anthill(_anthill)
{}

Ant::~Ant()
{

}

void Ant::decrease_food_need(int quantity)
{
    this->food_need -= quantity;
}

void Ant::Action()
{
    auto newState = m_state->Action(*this);
    if(newState)
        m_state = std::move(newState);
}

int Ant::get_food_need() const
{
    return food_need;
}

void Ant::set_food_need(int value)
{
    food_need = value;
}

int Ant::get_max_food_need() const
{
    return max_food_need;
}

void Ant::set_max_food_need(int value)
{
    max_food_need = value;
}

int Ant::get_time_to_transition() const
{
    return time_to_transition;
}

void Ant::set_time_to_transition(int value)
{
    time_to_transition = value;
}

bool Ant::get_is_queen() const
{
    return is_queen;
}

void Ant::set_is_queen(bool value)
{
    is_queen = value;
}

Anthill* Ant::get_anthill() const
{
    return m_anthill;
}

void Ant::set_anthill(Anthill *anthill)
{
    m_anthill = anthill;
}
