#ifndef MAINWINDOW_UNIVERSE_H
#define MAINWINDOW_UNIVERSE_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow_Universe;
}
QT_END_NAMESPACE

class MainWindow_Universe : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow_Universe(QWidget *parent = nullptr);
    ~MainWindow_Universe();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionSelect_All_triggered();

private:
    Ui::MainWindow_Universe *ui;
    QString m_filename;
};
#endif // MAINWINDOW_UNIVERSE_H
