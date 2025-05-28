#include "car.h"

Car::Car(QObject *parent)
    : QObject{parent}
{}

void Car::drive()
{
    qInfo() << "DRIVING!";
}

void Car::stop()
{
    qInfo() << "STOPPING!";
}
