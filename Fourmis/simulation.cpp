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
    //Shows parameters window
    fill_in_parameters();
    application.exec();

    //Generates Environnement
    env = Environnement(parameters.sizeX, parameters.sizeY, parameters.nb_obstacles, parameters.nb_foods);
    env.generate_ground(parameters);
    env.display_ground();
}

void Simulation::start()
{
    int incr = 0;
    while(1)
    {
        //Refreshes display
        application.processEvents();

        //Every 500ms
        if(incr%5 == 0)
        {
            //Each ant do an action
            for(auto& ant : env.get_anthill()->get_ants())
            {
                ant->Action();
                ant->set_time_to_transition(ant->get_time_to_transition() - 1);
                if(ant->get_time_to_transition() <=0)
                {
                    env.get_to_recreate().insert(std::pair<int, bool>(ant->getType(), ant->get_is_queen()));
                }
            }

            //deletes ants who reached their transition state
            env.get_anthill()->get_ants().erase(std::remove_if(
                                                                 env.get_anthill()->get_ants().begin(),
                                                                 env.get_anthill()->get_ants().end(),
                                                                 [](std::shared_ptr<Ant> _ant){return _ant->get_time_to_transition() <=0;}),
                                                                 env.get_anthill()->get_ants().end()
                                                           );
            //deletes ants who starved to death
            env.get_anthill()->get_ants().erase(std::remove_if(
                                                                 env.get_anthill()->get_ants().begin(),
                                                                 env.get_anthill()->get_ants().end(),
                                                                 [](std::shared_ptr<Ant> _ant){return (_ant->get_max_food_need() - _ant->get_food_need()) <=0;}),
                                                                 env.get_anthill()->get_ants().end()
                                                           );
            //creates new ants that have a new state
            transition();

            display_anthill_status(incr/5);

            apply_disappearance_rate();

            std::cout << "Tour : " << incr/5 << std::endl;
        }

        //Every 15sec
        if(incr%150 == 0)
            env.regenerate_food(2);

        std::this_thread::sleep_for (std::chrono::milliseconds(100));
        incr++;
    }
}

void Simulation::apply_disappearance_rate()
{
    for(auto& column : env.get_board())
    {
        for(auto& tile : column)
        {
            if(tile->getType() == 1 && dynamic_cast<Dirt*>(tile)->get_pheromone_rate() != 0)
            {
                //applies disappearance rate and update the map if there is no more pheromones on the block
                if(dynamic_cast<Dirt*>(tile)->apply_disappearance_rate(parameters.pheromone_disappearance_rate) == 0)
                    env.get_map().refresh_display(0, tile->get_coordinates().x, tile->get_coordinates().y);
            }
        }
    }
}

void Simulation::display_anthill_status(int current_round)
{
    //gets informations about the simulation
    int nb_ant = env.get_anthill()->get_ants().size();
    int nb_egg = env.get_anthill()->get_nb_ant_type(0);
    int nb_larva = env.get_anthill()->get_nb_ant_type(1);
    int nb_worker = env.get_anthill()->get_nb_ant_type(2);
    int nb_warrior = env.get_anthill()->get_nb_ant_type(3);
    int nb_queen = env.get_anthill()->get_nb_ant_type(4);
    int nb_max_ant = env.get_anthill()->get_max_ants_nb();
    int amount_food = env.get_anthill()->get_quantity_food_stock();
    int max_amount_food = env.get_anthill()->get_max_quantity_food_stock();

    //update information window (AnthillStatus)
    anthill_status.display(current_round, nb_ant, nb_egg, nb_larva, nb_worker, nb_warrior, nb_queen, nb_max_ant, amount_food, max_amount_food);
    anthill_status.show();
}

void Simulation::transition()
{
    for(auto& ant : env.get_to_recreate())
    {
        std::shared_ptr<Ant> newAnt;
        switch (ant.first)
        {
            case -1:
                newAnt = std::make_shared<Egg>(env, env.get_anthill(), ant.second, parameters.amount_food_need, parameters.time_to_transition);
                env.get_anthill()->get_ants().emplace_back(newAnt);
                break;
            case 0:
                newAnt = std::make_shared<Larva>(env, env.get_anthill(), ant.second, parameters.amount_food_need, parameters.time_to_transition);
                env.get_anthill()->get_ants().emplace_back(newAnt);
                break;
            case 1:
                newAnt = std::make_shared<Worker>(env, env.get_anthill(), ant.second, parameters.amount_food_need, parameters.time_to_transition);
                env.get_anthill()->get_ants().emplace_back(newAnt);
                break;
            case 2:
                newAnt = std::make_shared<Warrior>(env, env.get_anthill(), ant.second, parameters.amount_food_need, parameters.time_to_transition, parameters.carrying_capacity);
                env.get_anthill()->get_ants().emplace_back(newAnt);
                break;
            case 3:
                if(ant.second == true)
                {
                    newAnt = std::make_shared<Queen>(env, env.get_anthill(), ant.second, parameters.amount_food_need, parameters.time_to_transition);
                    env.get_anthill()->get_ants().emplace_back(newAnt);
                }
                break;
            case 4 :
                newAnt = std::make_shared<Queen>(env, env.get_anthill(), ant.second, parameters.amount_food_need, parameters.time_to_transition);
                env.get_anthill()->get_ants().emplace_back(newAnt);
                break;
            default:
                std::cout << "Switch case error in simulation, recreating ants after transition";
        }
    }
    env.get_to_recreate().clear();
}
