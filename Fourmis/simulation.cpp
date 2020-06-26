#include "simulation.h"
#include "anthill.h"
#include "ant.h"
#include "larva.h"
#include "worker.h"
#include "warrior.h"
#include "queen.h"
#include "egg.h"

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

        if(incr%5 == 0)
        {

            for(auto& ant : env.get_anthill()->get_ants())
            {
                ant->Action();
//                if((ant->get_max_food_need() - ant->get_food_need()) <=0)
//                {
//                    env.toRecreate.push_back(ant->getType(), ant->get_is_queen());
//                }
            }

//            env.get_anthill()->get_ants().erase(std::remove_if(
//                                                     env.get_anthill()->get_ants().begin(),
//                                                     env.get_anthill()->get_ants().end(),
//                                                     [](Ant& _ant){return (_ant.get_max_food_need() - _ant.get_food_need()) <=0;}),
//                                                     env.get_anthill()->get_ants().end()
//                                               );
//            for(auto& ant : env.toRecreate)
//            {
//                std::shared_ptr<Ant> newAnt;
//                switch (ant[0])
//                {
//                    case -1:
//                        newAnt = std::make_shared<Egg>(env, env.get_anthill(), ant[1], parameters.nb_max_food, parameters.time_to_transition);
//                        env.get_anthill()->get_ants().emplace_back(ant);
//                        break;
//                    case 0:
//                        newAnt = std::make_shared<Larva>(env, env.get_anthill(), ant[1], parameters.nb_max_food, parameters.time_to_transition);
//                        env.get_anthill()->get_ants().emplace_back(ant);
//                        break;
//                    case 1:
//                        newAnt = std::make_shared<Worker>(env, env.get_anthill(), ant[1], parameters.nb_max_food, parameters.time_to_transition);
//                        env.get_anthill()->get_ants().emplace_back(ant);
//                        break;
//                    case 2:
//                        newAnt = std::make_shared<Warrior>(env, env.get_anthill(), ant[1], parameters.nb_max_food, parameters.time_to_transition, parameters.carrying_capacity));
//                        env.get_anthill()->get_ants().emplace_back(ant);
//                        break;
//                    case 3:
//                        if(ant[1] == true)
//                        {
//                            newAnt = std::make_shared<Queen>(env, env.get_anthill(), ant[1], parameters.nb_max_food, parameters.time_to_transition, parameters.carrying_capacity));
//                            env.get_anthill()->get_ants().emplace_back(ant);
//                        }
//                        break;
//                    case 4 :
//                        break;
//                    default:
//                        std::cout << "Switch case error in simulation, recreating ants after transition";
//                }
//            }



//            for(auto& ant : env.get_anthill()->get_ants())
//            {
//                transition(ant);
//            }
////            env->get_anthill()->get_ants().erase(std::remove_if(
////                                                     env->get_anthill()->get_ants().begin(),
////                                                     env->get_anthill()->get_ants().end(),
////                                                     [](Ant& _ant){return _ant.get_time_to_transition() <=0;}),
////                                                     env->get_anthill()->get_ants().end()
////                                                             );
            std::cout << "Tour : " << incr/5 << std::endl;
            display_anthill_status();
            //apply_disappearance_rate();
        }

        if(incr%200 == 0)
            env.regenerate_food(2);

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
    for (int x = 0 ; x < env.getSizeX() ; x++)
    {
        for (int y = 0; y < env.getSizeY() ; y++)
        {
            if(env.getTile(x,y)->getType() == 1 && dynamic_cast<Dirt*>(env.getTile(x,y))->get_pheromone_rate() != 0)
            {
                dynamic_cast<Dirt*>(env.getTile(x,y))->apply_disappearance_rate(parameters.pheromone_disappearance_rate);
            }
        }
    }
}

void Simulation::display_anthill_status()
{
    int nb_ant = env.get_anthill()->get_ants().size();
    int nb_egg = env.get_anthill()->get_nb_ant_type(0);
    int nb_larva = env.get_anthill()->get_nb_ant_type(1);
    int nb_worker = env.get_anthill()->get_nb_ant_type(2);
    int nb_warrior = env.get_anthill()->get_nb_ant_type(3);
    int nb_max_ant = env.get_anthill()->get_max_ants_nb();
    int amount_food = env.get_anthill()->get_quantity_food_stock();
    int max_amount_food = env.get_anthill()->get_max_quantity_food_stock();
    anthill_status.display(nb_ant, nb_egg, nb_larva, nb_worker, nb_warrior, nb_max_ant, amount_food, max_amount_food);
    anthill_status.show();
}

void Simulation::transition(std::shared_ptr<Ant>& ant)
{
    ant->set_time_to_transition(ant->get_time_to_transition() - 1);
    if(ant->get_time_to_transition() == 0)
    {
        switch (ant->getType())
        {
        case 0:
            ant = std::make_shared<Larva>(env, env.get_anthill(), false, parameters.amount_food_need, parameters.time_to_transition);
            break;
        case 1:
            ant = std::make_shared<Worker>(env, env.get_anthill(), false, parameters.amount_food_need, parameters.time_to_transition);
            break;
        case 2:
            ant = std::make_shared<Warrior>(env, env.get_anthill(), false, parameters.amount_food_need, parameters.time_to_transition, parameters.carrying_capacity);
            break;
        }
    }
}
