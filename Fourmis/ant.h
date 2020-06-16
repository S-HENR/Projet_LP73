#ifndef ANT_H
#define ANT_H

#include "state.h"

#include <memory>

class Ant
{
public:
    Ant();
    Ant(bool _is_queen, int _food_need = 0, int _max_food_need = 0, int _time_to_transition = 10);
    ~Ant();
    void decrease_food_need();
    virtual void increase_food_need() = 0;
    virtual void eat() = 0;

    void Action();
    void FaireSonTraitement();

    int get_food_need() const;
    void set_food_need(int value);

    int get_max_food_need() const;
    void set_max_food_need(int value);

    int get_time_to_transition() const;
    void set_time_to_transition(int value);

    bool get_is_queen() const;
    void set_is_queen(bool value);

private:
    int coordinates[2];
    bool is_queen;
    int food_need;
    int max_food_need;
    int time_to_transition;

    std::unique_ptr<State> m_state = nullptr;
};

#endif // ANT_H
