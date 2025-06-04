#include "dialog1.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog1 w;
    w.show();
    return a.exec();
}
