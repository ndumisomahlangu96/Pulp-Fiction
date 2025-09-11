#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QtMath>
#include <QSettings>
#include <QVariant>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Set initial value of variables.
    int BoxVolume = 0;
    double CylinderVolume = 0;
    double TotalVolume = 0;
    int TotalWeight = 0;
    QString ContainerCode;

private slots:
    void on_pushButtonBox_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonCylinder_clicked();

    void on_pushButtonCode_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonLoad_clicked();



    void on_pushButtonRemove_clicked();

    void on_pushButtonClear_2_clicked();

    void on_pushButtonClose_clicked();

private:
    Ui::MainWindow *ui;
    void load();
    void save();
    void initialize();
    int serialnumber = 0;

};
#endif // MAINWINDOW_H
