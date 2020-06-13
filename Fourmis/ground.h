#ifndef GROUND_H
#define GROUND_H

class Ground
{
public:
    Ground(bool crossable);
    ~Ground();
    bool getCrossable();
    virtual void getValue() = 0;
    virtual int getType() = 0;
private:
    bool crossable;
};

#endif // GROUND_H
