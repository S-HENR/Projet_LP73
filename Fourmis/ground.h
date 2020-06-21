#ifndef GROUND_H
#define GROUND_H

#include "useful_functions.h"

class Ground
{
public:
    Ground(bool crossable, int _x, int _y);
    ~Ground();
    bool getCrossable();
    virtual int getType() = 0;

    coord get_coordinates() const;
    void set_coordinates(const int &x, const int &y);

private:
    bool crossable;
    struct coord coordinates;
};

#endif // GROUND_H
