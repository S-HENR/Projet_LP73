#include "map_display.h"

Map_display::Map_display()
{
    widget = new QWidget;
    gridLayout = new QGridLayout(widget);
    scrollArea = new QScrollArea;
    widget->setStyleSheet("background-color:#000;");
    gridLayout->setSpacing(0);
}

void Map_display::display(std::vector<std::vector<Ground*>>& board)
{
    //Initialize the grid (board) with images
    for(auto& column : board)
    {
        for(auto& tile : column)
        {
            label_img = new QLabel;
            switch (tile->getType()) {
                case 0:
                    label_img->setPixmap(QPixmap("../img/anthill.jpg"));
                    break;
                case 1:
                    label_img->setPixmap(QPixmap("../img/dirt.jpg"));
                    break;
                case 2:
                    label_img->setPixmap(QPixmap("../img/obstacle.jpg"));
                    break;
                case 3:
                    label_img->setPixmap(QPixmap("../img/food.jpg"));
                    break;
            }
            auto coordinates = tile->get_coordinates();
            gridLayout->addWidget(label_img, coordinates.y, coordinates.x);
        }
    }


    widget->setLayout(gridLayout);
    //Add a scrollbar to the window
    scrollArea->setWidget(widget);
    //Display the map
    scrollArea->showMaximized();

    //Initialize the view to display the Anthill in the middle of the window
    scrollArea->verticalScrollBar()->setValue(scrollArea->verticalScrollBar()->maximum()/2);
    scrollArea->horizontalScrollBar()->setValue(scrollArea->horizontalScrollBar()->maximum()/2);
}


void Map_display::refresh_display(int choice, int x, int y)
{
    label_img = new QLabel;

    /* Choice :
     * 0 : Set grid[x][y] to dirt
     * 1 : Set grid[x][y] to food
     * 2 : Put ant looking north on grid[x][y]
     * 3 : Put ant looking east on grid[x][y]
     * 4 : Put ant looking south on grid[x][y]
     * 5 : Put ant looking west on grid[x][y]
     */

    switch(choice)
    {
    case 0:
        label_img->setPixmap(QPixmap("../img/dirt.jpg"));
        break;
    case 1:
        label_img->setPixmap(QPixmap("../img/food.jpg"));
        break;
    case 2:
        label_img->setPixmap(QPixmap("../img/dirt-ant-north.jpg"));
        break;
    case 3:
        label_img->setPixmap(QPixmap("../img/dirt-ant-east.jpg"));
        break;
    case 4:
        label_img->setPixmap(QPixmap("../img/dirt-ant-south.jpg"));
        break;
    case 5:
        label_img->setPixmap(QPixmap("../img/dirt-ant-west.jpg"));
        break;
    }

    //update map[x][y]
    gridLayout->addWidget(label_img, y, x);
    scrollArea->setWidget(widget);
    //display the map updated
    scrollArea->show();
}
