/*
 * What
 * QVariant
 *
 * Why
 * Variant and unkown types-basic part of the meta system
 *
 * How
 * See below
 */

#include <QCoreApplication>
#include <QDebug>
#include <QVariant>

void test(QVariant value)   // Copy
{
    qInfo() << value;
    int i = 0;
    bool ok = false;
    i = value.toInt(&ok);
    if(ok)
    {
        qInfo() << "INT" << i;
    }
    else
    {
        qInfo() << "Not a int!";
    }
}

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

    QVariant value = 1;
    QVariant value2 = "Hello World";

    test(value);
    test(value2);

    return a.exec();
}
