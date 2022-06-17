#include "mainwindow.h"

#include <QApplication>
#include "cranialelectricalsimulation.h"
#include "cestests.h"


int main(int argc, char *argv[])
{
    CESTests();
    CranialElectricalSimulation ces;
    QApplication a(argc, argv);
    MainWindow w(&ces);
    w.show();
    return a.exec();
}
