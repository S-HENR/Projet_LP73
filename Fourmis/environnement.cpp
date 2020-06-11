#include "environnement.h"
#include "dirt.h"
#include "obstacle.h"
#include "food.h"
#include "anthill.h"

Environnement::Environnement(int height,int length, int food, int obstacle): food_number(food), obstacle_number(obstacle)
{
    size[0] = length;
    size[1] = height;

    std::vector<Ground*> lines(size[0], nullptr);
    board = std::vector<std::vector<Ground*>>(size[1], lines);
}

Environnement::~Environnement()
{
//    for (int i = 0 ; i < size[0]; i++)
//        for (int j = 0; j < size[1]; j++)
//        {
//            delete board[i][j];
//        }
}

void Environnement::generate_ground()
{
    int x = size[1]/2;
    int y = size[0]/2;
    board[x][y] = new Anthill();

    while(obstacle_number > 0)
    {
        x = rand()%size[1];
        y = rand()%size[0];
        if(!board[x][y])
        {
            board[x][y] = new Obstacle();
            obstacle_number--;
        }
    }
    while(food_number > 0)
    {
        x = rand()%size[1];
        y = rand()%size[0];
        if(!board[x][y])
        {
            board[x][y] = new Food();
            food_number--;
        }
    }
    for (int i = 0 ; i < size[1]; i++)
        for (int j = 0; j < size[0]; j++)
        {
            if(!board[i][j])
                board[i][j] = new Dirt();
        }
}

void Environnement::display_ground()
{
    for (int i = 0 ; i < size[1]; i++)
    {
        for (int j = 0; j < size[0]; j++)
        {
            board[i][j]->getValue();
        }
        std::cout <<std::endl;
    }
}
