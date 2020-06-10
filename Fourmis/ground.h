#ifndef GROUND_H
#define GROUND_H

class Ground
{
public:
    Ground(int coordinateX, int coordinateY, bool crossable);
    ~Ground();
    int getCoordinateX();
    int getCoordinateY();
    bool getCrossable();
    virtual void getValue() = 0;
private:
    int coordinates[2];
    bool crossable;
};

#endif // GROUND_H
