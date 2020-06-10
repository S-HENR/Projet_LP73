#include "environnement.h"
#include "dirt.h"
#include "obstacle.h"

Environnement::Environnement(int lenght,int height)
{
    size[0] = lenght;
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
    for (int i = 0 ; i < size[0]; i++)
        for (int j = 0; j < size[1]; j++)
        {
            board[i][j] = new Obstacle(1,1);
        }
}

void Environnement::display_ground()
{
    for (int i = 0 ; i < size[0]; i++)
        for (int j = 0; j < size[1]; j++)
        {
            board[i][j]->getValue();
        }
}
