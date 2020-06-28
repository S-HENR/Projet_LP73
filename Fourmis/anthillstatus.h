#ifndef ANTHILLSTATUS_H
#define ANTHILLSTATUS_H

#include <QMainWindow>

namespace Ui {
class AnthillStatus;
}

class AnthillStatus : public QMainWindow
{
    Q_OBJECT

public:
    explicit AnthillStatus(QWidget *parent = nullptr);
    ~AnthillStatus();
    void display(int current_round, int nb_ant, int nb_egg, int nb_larva, int nb_worker, int nb_warrior, int nb_queen, int nb_max_ant, int amount_food, int max_amount_food);
    bool get_stop_simu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AnthillStatus *ui;
    bool stop_simu;
};

#endif // ANTHILLSTATUS_H
