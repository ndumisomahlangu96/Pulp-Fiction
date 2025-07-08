#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include <QLabel> // Include QLabel

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(const QString &customerName, QWidget *parent = nullptr); // Modified constructor
    ~MainWindow2();

private:
    Ui::MainWindow2 *ui;
    QString m_customerName; // To store the received customer name
};

#endif // MAINWINDOW2_H
