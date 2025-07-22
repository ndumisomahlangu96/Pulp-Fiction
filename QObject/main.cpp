/*
    What
    QObject

    Why
    Base class for everything Qt (non-template)
    We have talked about this a LOT

    How
    See below
    review Signals, Slots, MOC, macros
*/

#include <QCoreApplication>
#include <QDebug>
#include "dog.h"
#include "cat.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.

    Cat cat;
    cat.setObjectName("Daniel");

    Dog dog;
    cat.setObjectName("Max");

    QObject::connect(&dog,&Dog::bark,&cat,&Cat::scared);
    QObject::connect(&cat,&Cat::runs,&dog,&Dog::chase);

    emit dog.bark();

    return a.exec();
}
