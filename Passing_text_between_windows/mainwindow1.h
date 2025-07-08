#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H

#include <QMainWindow>
#include "mainwindow2.h"        // Passing text between two different windows.

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow1;
}
QT_END_NAMESPACE

class MainWindow1 : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow1(QWidget *parent = nullptr);
    ~MainWindow1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow1 *ui;
};
#endif // MAINWINDOW1_H
