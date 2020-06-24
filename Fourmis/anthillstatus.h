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
    void display(int nb_ant, int nb_max_ant, int amount_food, int max_amount_food/*, int nb_ant_larva = 0, int nb_ant_worker = 0, int nb_ant_warrior = 0*/);

private:
    Ui::AnthillStatus *ui;
};

#endif // ANTHILLSTATUS_H
