/*
 * What
 * QStringList
 *
 * Why
 * Lists of strings
 * These are not arrays!
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

    QString data = "Hello world, how are you?";
    QStringList lst = data.split(" ");
    qInfo() << lst;

    foreach(QString str, lst)
    {
        qInfo() << str;
    }

    lst.sort(Qt::CaseInsensitive);
    qInfo() << lst;

    QString myvar = "Hello";
    if (lst.contains(myvar))
    {
        int index = lst.indexOf(myvar);
        qInfo() << lst.value(index);
    }

    return a.exec();


    return a.exec();
}
