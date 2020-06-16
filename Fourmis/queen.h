#ifndef QUEEN_H
#define QUEEN_H
#include "ant.h"

class Queen : public Ant
{
public:
    Queen();
    Queen(bool _is_queen = false, int _food_need = 0, int _max_food_need = 0, int _time_to_transition = 10);
    ~Queen();

    // Ant interface
public:
    void increase_food_need();
    void eat();

    bool get_is_hungry() const;
    void set_is_hungry(bool value);

private:
    bool is_hungry = false;
};

#endif // QUEEN_H
