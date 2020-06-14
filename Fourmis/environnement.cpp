#include "environnement.h"

Environnement::Environnement(int height,int length, int food, int obstacle): food_number(food), obstacle_number(obstacle)
{
    //Initialization of the map with nullptr
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
    //Initialization of Anthill ground :
    //Put the anthill in the middle of the map
    int x = size[1]/2;
    int y = size[0]/2;
    this->generate_anthill(x,y);

    //Initialization of Obstacle grounds :
    //Fill in the map with the amount of Obstacle ground wished
    srand((int)time(0));
    this->generate_obstacle();

    //Initialization of Food grounds :
    //Fill in the map with the amount of Food ground wished
    this->generate_food();

    //Initialization of Dirt grounds :
    //Fill in the blanks with Dirt Ground
    this->generate_dirt();
}

Ground* Environnement::getTile(int x, int y)
{
    return board[x][y];
}

int Environnement::getSizeX()
{
    return size[0];
}
int Environnement::getSizeY()
{
    return size[1];
}

void Environnement::generate_anthill(int x, int y)
{
    board[x][y] = new Anthill();
    board[x-1][y-1] = new Dirt();
    board[x-1][y] = new Dirt();
    board[x-1][y+1] = new Dirt();
    board[x][y-1] = new Dirt();
    board[x][y+1] = new Dirt();
    board[x+1][y-1] = new Dirt();
    board[x+1][y] = new Dirt();
    board[x+1][y+1] = new Dirt();
}

void Environnement::generate_obstacle()
{
    int x;
    int y;
    while(obstacle_number > 0)
    {
        x = rand()%size[1];
        y = rand()%size[0];
        template_obstacle(x,y);
    }
}

void Environnement::template_obstacle(int x, int y) {
    int pattern_chosen = 0;
    if(obstacle_number >= 4)
    {
        pattern_chosen = rand() % 6 + 1;
    }
    if(obstacle_number < 4)
    {
        pattern_chosen = rand() % 3 + 1;
    }
    if(obstacle_number < 3)
    {
        pattern_chosen = rand() % 2;
    }
    if(obstacle_number == 1)
    {
        pattern_chosen = 0;
    }


    switch (pattern_chosen) {

    //pattern : ■
    case 0:
        if(!board[x][y])
           board[x][y] = new Obstacle();

        obstacle_number--;
        break;

    //pattern : ■■
    case 1:
        if(!board[x][y])
           board[x][y] = new Obstacle();

        if(y+1 < size[0] && !board[x][y+1])
           board[x][y+1] = new Obstacle();

        obstacle_number -= 2;
        break;

    //pattern : ■■■
    case 2:
        if(!board[x][y])
           board[x][y] = new Obstacle();

        if(y+1 < size[0] && !board[x][y+1])
           board[x][y+1] = new Obstacle();

        if(y+2 < size[0] && !board[x][y+2])
           board[x][y+2] = new Obstacle();

        obstacle_number -= 3;
        break;

    //pattern :
    //■
    //■
    //■
    case 3:
        if(!board[x][y])
            board[x][y] = new Obstacle();

        if(x+1 < size[1] && !board[x+1][y])
            board[x+1][y] = new Obstacle();

        if(x+2 < size[1] && !board[x+2][y])
            board[x+2][y] = new Obstacle();

        obstacle_number -= 3;
        break;

    //pattern :
    //■
    //■
    //■■
    case 4:
        if(!board[x][y])
            board[x][y] = new Obstacle();

        if(x+1 < size[1] && !board[x+1][y])
            board[x+1][y] = new Obstacle();

        if(x+2 < size[1] && !board[x+2][y])
            board[x+2][y] = new Obstacle();

        if(x+2 < size[1] && y+1 < size[0] && !board[x+2][y+1])
            board[x+2][y+1] = new Obstacle();

        obstacle_number -= 4;
        break;

    //pattern :
    //■■
    //■■
    case 5:
        if(!board[x][y])
            board[x][y] = new Obstacle();

        if(y+1 < size[0] && !board[x][y+1])
            board[x][y+1] = new Obstacle();

        if(x+1 < size[1] && !board[x+1][y])
            board[x+1][y] = new Obstacle();

        if(x+1 < size[1] && y+1 < size[0] && !board[x+1][y+1])
            board[x+1][y+1] = new Obstacle();

        obstacle_number -= 4;
        break;

    //pattern :
    //■
    // ■
    // ■
    // ■
    case 6:
        if(!board[x][y])
            board[x][y] = new Obstacle();

        if(x+1 < size[1] && y+1 < size[0] && !board[x+1][y+1])
            board[x+1][y+1] = new Obstacle();

        if(x+2 < size[1] && y+1 < size[0] && !board[x+2][y+1])
            board[x+2][y+1] = new Obstacle();

        if(x+3 < size[1] && y+1 < size[0] && !board[x+3][y+1])
            board[x+3][y+1] = new Obstacle();

        obstacle_number -= 4;
        break;
    }
}

void Environnement::generate_food()
{
    int x;
    int y;
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
}

void Environnement::generate_dirt()
{
    for (int i = 0 ; i < size[1]; i++)
        for (int j = 0; j < size[0]; j++)
        {
            if(!board[i][j])
                board[i][j] = new Dirt();
        }
}

void Environnement::display_ground()
{
    map.display(board, size[1], size[0]);
}

int Environnement::get_typeof_tile(int x, int y)
{
    return board[x][y]->getType();
}

int Environnement::collect_food(int x, int y, int amount)
{
    int amount_food_collected = dynamic_cast<Food*>(board[x][y])->decrease_quantity(amount);
    if(dynamic_cast<Food*>(board[x][y])->get_quantity_food() == 0)
    {
        board[x][y] = new Dirt();
        map.refresh_display(0, x, y);
    }
    return amount_food_collected;
}
