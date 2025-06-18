#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>      // The QMessageBox class provides a modal dialog for informing the user or for asking the user a question and receiving an answer.
#include <QFile>            // The QFile class provides an interface for reading from and writing to files.
#include <QFileDialog>      // The QFileDialog class provides a dialog that allows users to select files or directories.
#include <QTextStream>      // The QTextStream class provides a convenient interface for reading and writing text.

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

private slots:
    void newFile();
    void openFile();
    void saveFile();
    void saveFileAs();
    void SelectNone();



private:
    Ui::MainWindow *ui;
    QString m_filename;
    bool m_saved;
};
#endif // MAINWINDOW_H
