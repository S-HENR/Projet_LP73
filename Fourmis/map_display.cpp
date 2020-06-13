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
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(widget);
    scrollArea->show();
}
