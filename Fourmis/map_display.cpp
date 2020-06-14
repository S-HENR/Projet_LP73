#include "map_display.h"

Map_display::Map_display()
{
    widget = new QWidget;
    gridLayout = new QGridLayout(widget);
    scrollArea = new QScrollArea;
    widget->setStyleSheet("background-color:#000;");
    gridLayout->setSpacing(0);
}

void Map_display::display(std::vector<std::vector<Ground*>>& board, int x, int y)
{
    //Initialize the grid with images
    for (int i = 0 ; i < x ; i++)
    {
        for (int j = 0; j < y ; j++)
        {
            label_img = new QLabel;
            switch (board[i][j]->getType()) {
                case 0:
                    label_img->setPixmap(QPixmap("../img/anthill.png"));
                    break;
                case 1:
                    label_img->setPixmap(QPixmap("../img/dirt.png"));
                    break;
                case 2:
                    label_img->setPixmap(QPixmap("../img/obstacle.png"));
                    break;
                case 3:
                    label_img->setPixmap(QPixmap("../img/food.png"));
                    break;
            }
            gridLayout->addWidget(label_img, i, j, 0);
        }
    }

    widget->setLayout(gridLayout);
    //Add a scrollbar to the window
    scrollArea->setWidget(widget);
    //Display the map
    scrollArea->show();

    //Initialize the view to display the Anthill in the middle of the window
    scrollArea->verticalScrollBar()->setValue(scrollArea->verticalScrollBar()->maximum()/2);
    scrollArea->horizontalScrollBar()->setValue(scrollArea->horizontalScrollBar()->maximum()/2);
}


void Map_display::refresh_display(int choice, int x, int y)
{
    label_img = new QLabel;

    switch(choice)
    {
    case 0:
        label_img->setPixmap(QPixmap("../img/dirt.png"));
        break;
    case 1:
        label_img->setPixmap(QPixmap("../img/food.png"));
        break;
    case 2:
        label_img->setPixmap(QPixmap("../img/dirt-ant-north.png"));
        break;
    case 3:
        label_img->setPixmap(QPixmap("../img/dirt-ant-east.png"));
        break;
    case 4:
        label_img->setPixmap(QPixmap("../img/dirt-ant-south.png"));
        break;
    case 5:
        label_img->setPixmap(QPixmap("../img/dirt-ant-west.png"));
        break;
    }


    gridLayout->addWidget(label_img, x, y, 0);
    scrollArea->setWidget(widget);
    scrollArea->show();
}
