#include "mainwindow.h"
#include "environnement.h"
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QGridLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.resize(100,50);
//    w.show();
    Environnement env(99,50,500,1000);
    env.generate_ground();
    env.display_ground();

    return a.exec();





    return 0;
}
