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

    double value = 5.75;
    qInfo() << "Double: " << value;

    int age = value;
    qInfo() << "Integer: " << age; // Implicit casting should not be trusted!


    age = (int)age; // We control this conversion
    qInfo() << "Age: " << age; // Explicit conversion should be trusted.

    return a.exec();
}
