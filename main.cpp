#include <QtGui/QApplication>
#include "mainwindow.h"
#include "time.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qsrand(time(NULL));
    w.show();

    return a.exec();
}
