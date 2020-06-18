#ifndef SIMULATION_H
#define SIMULATION_H
#include <QApplication>
#include <thread>
#include <chrono>
#include "parameters.h"
#include "environnement.h"

class Simulation
{
public:
    Simulation(int argc, char *argv[]);
    void initialize_simulation();
    void start();
private:
    QApplication application;
    Parameters parameters;
    void fill_in_parameters();
    void generate_environnement();
};

#endif // SIMULATION_H
