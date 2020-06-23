#include "anthillstatus.h"
#include "ui_anthillstatus.h"

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

void AnthillStatus::display(int nb_ant, int nb_ant_larva, int nb_ant_worker, int nb_ant_warrior, int nb_max_ant, int amount_food, int max_amount_food)
{
    ui->label_nb_ant->setText(QString::number(nb_ant) + "/" + QString::number(nb_max_ant));
    ui->label_nb_larva->setText(QString::number(nb_ant_larva));
    ui->label_nb_worker->setText(QString::number(nb_ant_worker));
    ui->label_nb_warrior->setText(QString::number(nb_ant_warrior));
    ui->label_nb_ant->setText(QString::number(amount_food) + "/" + QString::number(max_amount_food));
}
