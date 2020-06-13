#ifndef MAP_DISPLAY_H
#define MAP_DISPLAY_H
#include <QLabel>
#include <QPixmap>
#include <QGridLayout>
#include <QScrollArea>
#include <QWheelEvent>
#include "environnement.h"

class Map_display
{
public:
    Map_display();
    void display(std::vector<std::vector<Ground*>>& board, int x, int y);
private:
    QWidget *widget;
    QLabel *label_img;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWheelEvent *wheelEvent;
};

#endif // MAP_DISPLAY_H
