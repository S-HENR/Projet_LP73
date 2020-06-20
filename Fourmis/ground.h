#ifndef GROUND_H
#define GROUND_H

class Ground
{
public:
    Ground(bool crossable);
    ~Ground();
    bool getCrossable();
    virtual int getType() = 0;
private:
    bool crossable;
};

#endif // GROUND_H
