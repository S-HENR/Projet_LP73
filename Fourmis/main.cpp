#include "parameters.h"
#include "environnement.h"
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QGridLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Parameters parameters;
    parameters.show();
    a.exec();
    Environnement env(parameters.sizeX, parameters.sizeY, parameters.nb_obstacles, parameters.nb_foods);
    env.generate_ground();
    env.display_ground();
    a.exec();

    return 0;
}
