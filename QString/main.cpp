/*
 * What
 * QString
 *
 * Why
 * Qts universal string class
 *
 * How
 * See below
 */

#include <QDebug>
#include <QCoreApplication>

void test(QString name)     // COPY
{
    qInfo() << name;
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

    QString name = "Ndumiso Mahlangu";
    qInfo() << name;
    qInfo() << name.mid(1,3);
    qInfo() << name.insert(0,"Mr. ");
    qInfo() << name.split(" ");

    int index = name.indexOf(" ");
    if(index > -1)
    {
        qInfo() << name.remove(0,index).trimmed();
    }

    QString title = "Teacher";
    QString full = name.trimmed() + " " + title;
    qInfo() << full;
    qInfo() << full.toUtf8();
    test(full);

    return a.exec();
}
