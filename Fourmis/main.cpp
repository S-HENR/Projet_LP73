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

//#include <iostream>
//#include <vector>
//#include  "AStar.hpp"

//int main()
//{
//    AStar::Generator generator;
//    // Set 2d map size.
//    generator.setWorldSize({25, 25});
//    // You can use a few heuristics : manhattan, euclidean or octagonal.
//    generator.setHeuristic(AStar::Heuristic::euclidean);
//    generator.setDiagonalMovement(true);
//    generator.addCollision({2,2});
//    std::cout << "Generate path ... \n";
//    // This method returns vector of coordinates from target to source.
//    auto path = generator.findPath({0, 0}, {20, 20});


//    for(auto& coordinate : path) {
//        std::cout << coordinate.x << " " << coordinate.y << "\n";
//    }

//    std::vector<int> coordinates(2);
//    std::vector<std::vector<int>> steps;
//    int counter = 0;
//    for(auto& coordinate : path) {
//        coordinates[0] = coordinate.x;
//        coordinates[1] = coordinate.y;
//        steps.push_back(coordinates);
//        counter++;
//    }
//    std::cout << "EHEHEHEEH" << std::endl;



//    while(steps.size() > 0)
//    {
//        std::cout << steps[0][0] << " " << steps[0][1] << std::endl;
//        steps.erase(steps.begin());
//    }
//}
