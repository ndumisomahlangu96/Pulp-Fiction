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
    QString data = "Hello world how are you";
    QList<QString> list = data.split(" ");

    foreach(QString word, list)
    {
        qInfo() << word;
    }

    QList<int> age({44, 56, 21, 13});
    age.append(99);
    age.remove(1);
    qInfo() << age;

    foreach(int word, age)
    {
        qInfo() << word;
    }

    return a.exec();
}
