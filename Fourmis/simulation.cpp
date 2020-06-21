#include "simulation.h"
#include "anthill.h"

Simulation::Simulation(int argc, char *argv[]) : application(argc, argv)
{

}

void Simulation::fill_in_parameters()
{
    parameters.show();
}
void Simulation::initialize_simulation()
{

    fill_in_parameters();
    application.exec();
    *env = Environnement(parameters.sizeX, parameters.sizeY, parameters.nb_obstacles, parameters.nb_foods);
    env->generate_ground(parameters);
    env->display_ground();
}

void Simulation::start()
{
    int incr = 0;
    while(1)
    {
        application.processEvents();

        if(incr%20 == 0)
        {
//            for(auto&& ant : env->get_anthill()->get_ants())
//            {
//                ant.Action();
//            }


            std::cout << "Tour : " << incr/20 << std::endl;
        }
        std::this_thread::sleep_for (std::chrono::milliseconds(100));
        incr++;
//        if(incr == 100)
//        {
//            break;
//        }
    }
}
