/*
 * What
 * QByteArray
 *
 * Why
 * Must have class for working with data
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
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.

    QString greeting = "Hello World";
    QByteArray buffer(greeting.toUtf8());
    buffer.append("!");
    qInfo() << buffer;

    qInfo() << buffer.rightJustified(20,'.');
    qInfo() << buffer.at(buffer.length()-1);

    QString modified(buffer);
    qInfo() << modified;

    // Basic encoding and decoding
    qInfo() << buffer.toBase64();
    qInfo() << buffer.toHex();





    return a.exec();
}
