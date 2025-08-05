/*
 * What
 * QVector
 *
 * Why
 * QVector is an alias for QList.
 * In Qt 5 this used to be a different class. Now QVector and QList are the same class.
 *
 * How
 * See below
 */

#include <QCoreApplication>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.

    QString data = "Hello world, how are you?";
    QVector<QString> list = data.split(" ");

    foreach(QString word, list)
    {
        qInfo() << word;
    }

    QVector<int> ages({44, 56, 21, 13});
    foreach(int age, ages)
    {
        qInfo() << age;
    }

    return a.exec();
}
