#ifndef MAINWINDOWSHOP_H
#define MAINWINDOWSHOP_H

#include <QMainWindow>
#include "mainwindow.h"                 // Passing text between the two different windows.
#include <QMessageBox>                  // The QMessageBox class provides a modal dialog for informing the user or for asking the user a question and receiving an answer.
#include <QDateTime>                    // The QDateTime class provides date and time functions.
#include <QFile>                        // The QFile class provides an interface for reading from and writing to files.
#include <QFileDialog>                  // The QFileDialog class provides a dialog that allows users to select files or directories.
#include <QTextStream>                  // The QTextStream class provides a convenient interface for reading and writing text.
#include <QLabel>                       // The QLabel widget provides a text or image display.
#include <QStatusBar>                   // The QStatusBar class provides a horizontal bar suitable for presenting status information.
#include <QDebug>                       // The QDebug class provides an output stream for debugging information.
#include <QPlainTextEdit>               // The QPlainTextEdit class provides a widget that is used to edit and display plain text.

namespace Ui {
class MainWindowShop;
}

class MainWindowShop : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowShop(const QString &customerName, QWidget *parent = nullptr);        // Modified constructor
    ~MainWindowShop();

private slots:
    // Functions to setup the Toolbar.
    void actionToolbarTop();
    void actionToolbarRight();
    void actionToolbarLeft();
    void actionToolbarBottom();
    void on_actionToolbar_movable_toggled(bool arg1);
    void on_actionToolbar_floatable_toggled(bool arg1);

    // Functions to control the text file used to store items.
    void newFile();
    void openFile();
    void saveFile();
    void saveFileAs();

    // Function used to edit plain text.
    void selectNone();

    // Save the data to textfile and close the mainwindow shop.
    void on_pushButtonCloseApp_clicked();

private:
    Ui::MainWindowShop *ui;
    QString m_customerName; // To store the received customer name.

    QString m_filename;
    bool m_saved;

    // Functions to setup the Statusbar.
    void setupStatusbar();
    void updateStatus(QString message);
};

#endif // MAINWINDOWSHOP_H
