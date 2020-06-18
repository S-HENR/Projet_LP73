#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QMainWindow>
#include <fstream>
#include <iostream>

namespace Ui {
class Parameters;
}

class Parameters : public QMainWindow
{
    Q_OBJECT

public:
    explicit Parameters(QWidget *parent = nullptr);
    ~Parameters();
    int sizeX;
    int sizeY;
    int nb_obstacles;
    int nb_foods;
    float pheromone_disappearance_rate;
    int nb_max_ants;
    int nb_max_food;
    int nb_init_larvas;
    int nb_init_workers;
    int nb_init_warriors;
    int amount_food_need;
    int time_to_transition;
    int carrying_capacity;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Parameters *ui;
};

#endif // PARAMETERS_H
