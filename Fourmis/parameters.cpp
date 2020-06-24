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
    std::ofstream save;
    save.open("../save.txt");

    sizeX = ui->lineEdit_1->text().toInt() ? ui->lineEdit_1->text().toInt() : 15;
    save << sizeX << '\n';

    sizeY = ui->lineEdit_2->text().toInt() ? ui->lineEdit_2->text().toInt() : 15;
    save << sizeY << '\n';

    nb_obstacles = ui->lineEdit_3->text().toInt() ? ui->lineEdit_3->text().toInt() : 50;
    save << nb_obstacles << '\n';

    nb_foods = ui->lineEdit_4->text().toInt() ? ui->lineEdit_4->text().toInt() : 50;
    save << nb_foods << '\n';

    pheromone_disappearance_rate = ui->lineEdit_5->text().toInt() ? ui->lineEdit_5->text().toFloat() : 0.95;
    save << pheromone_disappearance_rate << '\n';

    nb_max_ants = ui->lineEdit_6->text().toInt() ? ui->lineEdit_6->text().toInt() : 30;
    save << nb_max_ants << '\n';

    nb_max_food = ui->lineEdit_7->text().toInt() ? ui->lineEdit_7->text().toInt() : 30;
    save << nb_max_food << '\n';

    nb_init_larvas = ui->lineEdit_8->text().toInt() ? ui->lineEdit_8->text().toInt() : 0;
    save << nb_init_larvas << '\n';

    nb_init_workers = ui->lineEdit_9->text().toInt() ? ui->lineEdit_9->text().toInt() : 2;
    save << nb_init_workers << '\n';

    nb_init_warriors = ui->lineEdit_10->text().toInt() ? ui->lineEdit_10->text().toInt() : 3;
    save << nb_init_warriors << '\n';

    amount_food_need = ui->lineEdit_11->text().toInt() ? ui->lineEdit_11->text().toInt() : 30;
    save << amount_food_need << '\n';

    time_to_transition = ui->lineEdit_12->text().toInt() ? ui->lineEdit_12->text().toInt() : 100;
    save << time_to_transition << '\n';

    carrying_capacity = ui->lineEdit_13->text().toInt() ? ui->lineEdit_13->text().toInt() : 10;
    save << carrying_capacity << '\n';

    save.close();
    this->close();
}


void Parameters::on_pushButton_2_clicked()
{
    std::string line;
    std::ifstream save("../save.txt");

    std::getline(save, line);
    sizeX = std::stoi(line);

    std::getline(save, line);
    sizeY = std::stoi(line);

    std::getline(save, line);
    nb_obstacles = std::stoi(line);

    std::getline(save, line);
    nb_foods = std::stoi(line);

    std::getline(save, line);
    pheromone_disappearance_rate = std::stof(line);

    std::getline(save, line);
    nb_max_ants = std::stoi(line);

    std::getline(save, line);
    nb_max_food = std::stoi(line);

    std::getline(save, line);
    nb_init_larvas = std::stoi(line);

    std::getline(save, line);
    nb_init_workers = std::stoi(line);

    std::getline(save, line);
    nb_init_warriors = std::stoi(line);

    std::getline(save, line);
    amount_food_need = std::stoi(line);

    std::getline(save, line);
    time_to_transition = std::stoi(line);

    std::getline(save, line);
    carrying_capacity = std::stoi(line);

    save.close();
    this->close();
}
