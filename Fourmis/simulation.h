#ifndef SIMULATION_H
#define SIMULATION_H
#include <QApplication>
#include <thread>
#include <chrono>
#include "parameters.h"
#include "environnement.h"
#include "anthillstatus.h"

class Simulation
{
public:
    Simulation(int argc, char *argv[]);
    void initialize_simulation();
    void start();
private:
    QApplication application;
    Parameters parameters;
    Environnement env;
    AnthillStatus anthill_status;
    void fill_in_parameters();
    void generate_environnement();
    void display_anthill_status();
};

#endif // SIMULATION_H
