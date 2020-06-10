#ifndef ANT_H
#define ANT_H

class Ant
{
public:
    Ant();
    ~Ant();
    int decrease_food_need();
    virtual int increase_food_need() = 0;
    virtual void eat() = 0;

private:
    int coordinates[2];
    int food_need;
    int max_food_need;
    int time_to_transition;
    bool is_queen;
};

#endif // ANT_H
