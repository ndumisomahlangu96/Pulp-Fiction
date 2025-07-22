/*
 * What
 * Qt date time classes
 *
 * Why
 * Makes dates and times easy
 *
 * How
 * See below
 */

#include <QCoreApplication>
#include <QDebug>
#include <QDate>
#include <QTime>
#include <QDateTime>

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

    QDate today = QDate::currentDate();
    qInfo() << today;
    qInfo() << today.addDays(1);
    qInfo() << today.addYears(20);

    qInfo() << "ISODate" << today.toString(Qt::DateFormat::ISODate);
    qInfo() << "RFC2822Date" << today.toString(Qt::DateFormat::RFC2822Date);
    qInfo() << "Text Date" << today.toString(Qt::DateFormat::TextDate);

    QDateTime current = QDateTime::currentDateTime();

    qInfo() << current;
    QDateTime expire = current.addDays(45);
    qInfo() << "Expire on" << expire;

    if(current > expire)
    {
        qInfo() << "Expired!";
    }
    else
    {
        qInfo() << "Not Expired!";
    }


    return a.exec();
}
