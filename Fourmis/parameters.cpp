#include "parameters.h"
#include "ui_parameters.h"

Parameters::Parameters(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Parameters)
{
    ui->setupUi(this);
}

Parameters::~Parameters()
{
    delete ui;
}

void Parameters::on_pushButton_clicked()
{
    sizeX = ui->lineEdit_1->text().toInt();
    sizeY = ui->lineEdit_2->text().toInt();
    nb_obstacles = ui->lineEdit_3->text().toInt();
    nb_foods = ui->lineEdit_4->text().toInt();
    pheromone_disappearance_rate = ui->lineEdit_5->text().toInt();
    nb_max_ants = ui->lineEdit_6->text().toInt();
    nb_max_food = ui->lineEdit_7->text().toInt();
    nb_init_larvas = ui->lineEdit_8->text().toInt();
    nb_init_workers = ui->lineEdit_9->text().toInt();
    nb_init_warriors = ui->lineEdit_10->text().toInt();
    amount_food_need = ui->lineEdit_11->text().toInt();
    time_to_transition = ui->lineEdit_12->text().toInt();
    carrying_capacity = ui->lineEdit_13->text().toInt();
    this->close();
}
