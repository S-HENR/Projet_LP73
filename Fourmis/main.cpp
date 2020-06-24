#include "parameters.h"
#include "simulation.h"
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QGridLayout>


int main(int argc, char *argv[])
{
    try{
        Simulation simulation(argc, argv);
        simulation.initialize_simulation();
        simulation.start();

    } catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    } catch (...) {
        std::cerr << "Unexpected error" << std::endl;
    }


    return 0;
}
