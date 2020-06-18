#include "parameters.h"
#include "simulation.h"
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QGridLayout>


int main(int argc, char *argv[])
{

    Simulation simulation(argc, argv);
    simulation.initialize_simulation();
    simulation.start();

    return 0;
}
