#ifndef ANT_H
#define ANT_H

#include "anthill.h"
#include "state.h"

#include <memory>

class Ant
{
public:
    Ant() = delete;
    Ant(Environnement& env, Anthill* _anthill, bool _is_queen, int _max_food_need = 0, int _time_to_transition = 10, float _food_need = 0, std::unique_ptr<State> _state = nullptr);
    ~Ant();
    void decrease_food_need(int quantity);
    virtual void increase_food_need() = 0;
    virtual void eat() = 0;
    virtual int getType() = 0;

    void Action();

    float get_food_need() const;
    void set_food_need(float value);

    int get_max_food_need() const;
    void set_max_food_need(int value);

    int get_time_to_transition() const;
    void set_time_to_transition(int value);

    bool get_is_queen() const;
    void set_is_queen(bool value);

    Anthill* get_anthill();
    void set_anthill(Anthill *anthill);

    Environnement& get_env() const;
    void set_env(const Environnement &env);

    coord get_coordinates() const;
    void set_coordinates(const int &x, const int &y);

    coord get_old_tile() const;
    void set_old_tile(const int &x, const int &y);

private:
    coord coordinates;
    coord old_tile;
    bool is_queen;
    float food_need;
    int max_food_need;
    int time_to_transition;

    std::unique_ptr<State> m_state = nullptr;
    Anthill* m_anthill = nullptr;
    Environnement& m_env;
};

#endif // ANT_H
