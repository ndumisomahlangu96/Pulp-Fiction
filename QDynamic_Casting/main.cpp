/*
 * What
 * Dynamic Casting
 *
 * Why Casting is complex, we want to make it easier.
 * The dynamic_cast operator ensures that if you convert a pointer to class A
 * to a pointer to class B, the object of type A pointed to by the former belongs
 * to an object of type B or a class derived from B as a base class subobject.
 *
 * How
 * https://en.cppreference.com/w/cpp/language/dynamic_cast
 *
 */



#include <QCoreApplication>
#include "feline.h"
#include "QDebug"
#include "car.h"
#include "racecar.h"

// Dynamic cast
// dynamic_cast can be used only with pointers and reference to objects.
// Its purpose is to ensure that the result of the type conversion is a valid complete object of the requested object.


void testDrive(Car* obj)
{
    obj->drive();
    obj->stop();
}

void race(RaceCar* obj)
{
    obj->drive();
    obj->stop();
    obj->gofast();
}


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.

    RaceCar* player1 = new RaceCar(&app);
    testDrive(player1);     // Implicit conversion

    // Correct Way - Explicit conversion
    Car* obj = dynamic_cast<Car*>(player1);
    // Explicity conversion
    if (obj) testDrive(obj);

    Feline* cat = new Feline(&app);
    Car* catcar = dynamic_cast<Car*>(cat);
    qInfo() << "CatCar" << catcar;
    if (catcar) testDrive(catcar);

    return app.exec();
}
