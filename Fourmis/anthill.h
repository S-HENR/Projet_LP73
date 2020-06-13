#ifndef ANTHILL_H
#define ANTHILL_H
#include <iostream>
#include "ground.h"

class Anthill : public Ground
{
public:
    Anthill();
    ~Anthill();
    virtual void getValue();
    virtual int getType();
private:
    int coordinates[2];
};

#endif // ANTHILL_H
