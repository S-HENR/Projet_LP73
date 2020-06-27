#include "environnement.h"
#include "anthill.h"

Environnement::Environnement(int length,int height, int obstacle, int food):
    food_number(food),
    obstacle_number(obstacle),
    generator((std::random_device())())
{
    //Initialization of the map with nullptr
    size[0] = length;
    size[1] = height;
    std::vector<Ground*> lines(size[1], nullptr);
    board = std::vector<std::vector<Ground*>>(size[0], lines);
}

Environnement::~Environnement()
{

}

void Environnement::generate_ground(Parameters& parameters)
{
    //Initialization of Anthill ground :
    //Put the anthill in the middle of the map surronded by dirt
    int x = size[0]/2;
    int y = size[1]/2;
    this->generate_anthill(x,y, parameters);

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

void Environnement::generate_anthill(int x, int y, Parameters& parameters)
{
    anthill = new Anthill(*this, parameters, x, y);

    board[x][y] = anthill;
    board[x-1][y-1] = new Dirt(x-1,y-1);
    board[x-1][y] = new Dirt(x-1,y);
    board[x-1][y+1] = new Dirt(x-1,y+1);
    board[x][y-1] = new Dirt(x,y-1);
    board[x][y+1] = new Dirt(x,y+1);
    board[x+1][y-1] = new Dirt(x+1,y-1);
    board[x+1][y] = new Dirt(x+1,y);
    board[x+1][y+1] = new Dirt(x+1,y+1);
}

void Environnement::generate_obstacle()
{
    int x;
    int y;

    while(obstacle_number > 0)
    {
        x = rand()%size[0];
        y = rand()%size[1];
        template_obstacle(x,y);
    }
}

void Environnement::template_obstacle(int x, int y) {
    //Ramdom choice between 6 different patterns according number of obstacles remaining

    int pattern_chosen = 0;

    //Every pattern except the first are eligible to be chosen.
    if(obstacle_number >= 4)
    {
        pattern_chosen = rand() % 6 + 1;
    }

    //Patterns with 3 or less obstacles except the first are eligible to be chosen.
    if(obstacle_number < 4)
    {
        pattern_chosen = rand() % 3 + 1;
    }

    //Patterns with 2 or less obstacles are eligible to be chosen.
    if(obstacle_number < 3)
    {
        pattern_chosen = rand() % 2;
    }

    //Only the first pattern is eligible to be chosen
    if(obstacle_number == 1)
    {
        pattern_chosen = 0;
    }

    //Apply pattern ramdomly selected
    switch (pattern_chosen) {

    //pattern : ■
    case 0:
        if(!board[x][y])
        {
           board[x][y] = new Obstacle(x,y);
           obstacle_number--;
        }

        break;

    //pattern : ■■
    case 1:
        if(!board[x][y])
        {
           board[x][y] = new Obstacle(x,y);
           obstacle_number--;
        }

        if(x+1 < size[0] && !board[x+1][y])
        {
           board[x+1][y] = new Obstacle(x+1,y);
           obstacle_number--;
        }

        break;

    //pattern : ■■■
    case 2:
        if(!board[x][y])
        {
           board[x][y] = new Obstacle(x,y);
           obstacle_number--;
        }

        if(x+1 < size[0] && !board[x+1][y])
        {
           board[x+1][y] = new Obstacle(x+1,y);
           obstacle_number--;
        }

        if(x+2 < size[0] && !board[x+2][y])
        {
           board[x+2][y] = new Obstacle(x+2,y);
           obstacle_number--;
        }

        break;

    //pattern :
    //■
    //■
    //■
    case 3:
        if(!board[x][y])
        {
            board[x][y] = new Obstacle(x,y);
            obstacle_number--;
         }

        if(y+1 < size[1] && !board[x][y+1])
        {
            board[x][y+1] = new Obstacle(x,y+1);
            obstacle_number--;
         }

        if(y+2 < size[1] && !board[x][y+2])
        {
            board[x][y+2] = new Obstacle(x,y+2);
            obstacle_number--;
         }

        break;

    //pattern :
    //■
    //■
    //■■
    case 4:
        if(!board[x][y])
        {
            board[x][y] = new Obstacle(x,y);
            obstacle_number--;
         }

        if(y+1 < size[1] && !board[x][y+1])
        {
            board[x][y+1] = new Obstacle(x,y+1);
            obstacle_number--;
         }

        if(y+2 < size[1] && !board[x][y+2])
        {
            board[x][y+2] = new Obstacle(x,y+2);
            obstacle_number--;
         }

        if(y+2 < size[1] && x+1 < size[0] && !board[x+1][y+2])
        {
            board[x+1][y+2] = new Obstacle(x+1,y+2);
            obstacle_number--;
         }

        break;

    //pattern :
    //■■
    //■■
    case 5:
        if(!board[x][y])
        {
            board[x][y] = new Obstacle(x,y);
            obstacle_number--;
         }

        if(y+1 < size[1] && !board[x][y+1])
        {
            board[x][y+1] = new Obstacle(x,y+1);
            obstacle_number--;
         }

        if(x+1 < size[0] && !board[x+1][y])
        {
            board[x+1][y] = new Obstacle(x+1,y);
            obstacle_number--;
         }

        if(x+1 < size[0] && y+1 < size[1] && !board[x+1][y+1])
        {
            board[x+1][y+1] = new Obstacle(x+1,y+1);
            obstacle_number--;
         }

        break;

    //pattern :
    //■
    // ■
    // ■
    // ■
    case 6:
        if(!board[x][y])
        {
            board[x][y] = new Obstacle(x,y);
            obstacle_number--;
         }

        if(x+1 < size[0] && y+1 < size[1] && !board[x+1][y+1])
        {
            board[x+1][y+1] = new Obstacle(x+1,y+1);
            obstacle_number--;
         }

        if(x+1 < size[0] && y+2 < size[1] && !board[x+1][y+2])
        {
            board[x+1][y+2] = new Obstacle(x+1,y+2);
            obstacle_number--;
         }

        if(x+1 < size[0] && y+3 < size[1] && !board[x+1][y+3])
        {
            board[x+1][y+3] = new Obstacle(x+1,y+3);
            obstacle_number--;
         }

        break;
    }
}

void Environnement::generate_food()
{
    int x;
    int y;
    int fd_nb = food_number;
    while(fd_nb > 0)
    {
        x = rand()%size[0];
        y = rand()%size[1];
        if(!board[x][y])
        {
            board[x][y] = new Food(x,y);
            fd_nb--;
        }
    }
}

void Environnement::generate_dirt()
{


    for (int x = 0 ; x < size[0]; x++)
        for (int y = 0; y < size[1]; y++)
        {
            if(!board[x][y])
                board[x][y] = new Dirt(x,y);
        }
}

void Environnement::display_ground()
{
    map.display(board);
}

Anthill *Environnement::get_anthill()
{
    return anthill;
}

void Environnement::set_anthill(Anthill *value)
{
    anthill = value;
}

Map_display Environnement::get_map() const
{
    return map;
}

std::vector<std::vector<Ground *> > Environnement::get_board() const
{
    return board;
}

int Environnement::generate_random(const int range_from, const int range_to)
{
    std::uniform_int_distribution<int> distr(range_from, range_to);
    return distr(generator);
}

std::multimap<int, bool>& Environnement::get_to_recreate()
{
    return toRecreate;
}

void Environnement::set_to_recreate(const std::multimap<int, bool> &value)
{
    toRecreate = value;
}

int Environnement::get_typeof_tile(int x, int y)
{
    return board[x][y]->getType();
}

int Environnement::collect_food(int x, int y, int amount)
{
    int amount_food_collected = dynamic_cast<Food*>(board[x][y])->decrease_quantity(amount);

    //if food block empty, it is replaced by a dirt block and the map is refreshed
    if(dynamic_cast<Food*>(board[x][y])->get_quantity_food() <= 0)
    {
        food_number--;
        board[x][y] = new Dirt(x,y);
        map.refresh_display(0, x, y);
    }
    return amount_food_collected;
}

void Environnement::regenerate_food(int amount)
{
    int x;
    int y;
    while(amount > 0)
    {
        x = rand()%size[0];
        y = rand()%size[1];
        if(board[x][y]->getType() == 1)
        {
            board[x][y] = new Food(x,y);
            map.refresh_display(1, x, y);
            food_number++;
            amount--;
        }
    }
}
