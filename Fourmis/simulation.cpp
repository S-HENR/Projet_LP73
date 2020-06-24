#include "simulation.h"
#include "anthill.h"
#include "ant.h"

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
    env = Environnement(parameters.sizeX, parameters.sizeY, parameters.nb_obstacles, parameters.nb_foods);
    env.generate_ground(parameters);
    env.display_ground();
}

void Simulation::start()
{
    int incr = 0;
    while(1)
    {
        application.processEvents();

        if(incr%10 == 0)
        {
            for(auto& ant : env.get_anthill()->get_ants())
            {
                ant->Action();
            }
////            env->get_anthill()->get_ants().erase(std::remove_if(
////                                                     env->get_anthill()->get_ants().begin(),
////                                                     env->get_anthill()->get_ants().end(),
////                                                     [](Ant& _ant){return _ant.get_time_to_transition() <=0;}),
////                                                     env->get_anthill()->get_ants().end()
////                                                             );


            std::cout << "Tour : " << incr/10 << std::endl;
            display_anthill_status();
            //apply_disappearance_rate();
        }
        std::this_thread::sleep_for (std::chrono::milliseconds(100));
        incr++;
//        if(incr == 100)
//        {
//            break;
//        }
    }
}

void Simulation::apply_disappearance_rate()
{
    for (int i = 0 ; i < env.getSizeY() ; i++)
    {
        for (int j = 0; j < env.getSizeX() ; j++)
        {
            if(env.getTile(i,j)->getType() == 1 && dynamic_cast<Dirt*>(env.getTile(i,j))->get_pheromone_rate() != 0)
            {
                dynamic_cast<Dirt*>(env.getTile(i,j))->apply_disappearance_rate(parameters.pheromone_disappearance_rate);
            }
        }
    }
}

void Simulation::display_anthill_status()
{
    int nb_ant = env.get_anthill()->get_ants().size();
    int nb_max_ant = env.get_anthill()->get_max_ants_nb();
    int amount_food = env.get_anthill()->get_quantity_food_stock();
    int max_amount_food = env.get_anthill()->get_max_quantity_food_stock();
    anthill_status.display(nb_ant, nb_max_ant, amount_food, max_amount_food);
    anthill_status.show();
}
