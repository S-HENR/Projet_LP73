#include "anthillstatus.h"
#include "ui_anthillstatus.h"
#include <iostream>
AnthillStatus::AnthillStatus(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnthillStatus)
{
    ui->setupUi(this);
}

AnthillStatus::~AnthillStatus()
{
    delete ui;
}

void AnthillStatus::display(int nb_ant, int nb_max_ant, int amount_food, int max_amount_food/*, int nb_ant_larva = 0, int nb_ant_worker = 0, int nb_ant_warrior = 0*/)
{
    ui->label_nb_ant->setText(QString::number(nb_ant) + "/" + QString::number(nb_max_ant));
//    ui->label_nb_larva->setText(QString::number(nb_ant_larva));
//    ui->label_nb_worker->setText(QString::number(nb_ant_worker));
//    ui->label_nb_warrior->setText(QString::number(nb_ant_warrior));
    ui->label_amount_food->setText(QString::number(amount_food) + "/" + QString::number(max_amount_food));
}
