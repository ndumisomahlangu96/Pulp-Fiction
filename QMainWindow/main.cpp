#include "mainwindow_universe.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow_Universe w;
    w.show();
    return a.exec();
}
