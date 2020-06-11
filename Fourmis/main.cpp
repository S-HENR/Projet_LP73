#include "mainwindow.h"
#include "environnement.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    Environnement myEnv{};
    return a.exec();
}
