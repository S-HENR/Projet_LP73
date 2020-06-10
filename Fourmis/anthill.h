#ifndef ANTHILL_H
#define ANTHILL_H
#include "ground.h"

class Anthill : public Ground
{
public:
    Anthill(int coordinateX, int coordinateY, bool crossable);
};

#endif // ANTHILL_H
