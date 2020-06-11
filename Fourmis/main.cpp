#include "mainwindow.h"
#include "environnement.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();*/

    Environnement env(5,5,10,5);

    //return a.exec();
    env.generate_ground();
    env.display_ground();

    return 0;
}
