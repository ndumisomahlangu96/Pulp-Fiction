#include "mainwindow_universe.h"
#include "./ui_mainwindow_universe.h"

MainWindow_Universe::MainWindow_Universe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow_Universe)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->plainTextEdit);


}

MainWindow_Universe::~MainWindow_Universe()
{
    delete ui;
}

void MainWindow_Universe::on_actionNew_triggered()
{
    ui->plainTextEdit->clear();
    ui->statusbar->showMessage(" ");
    m_filename.clear();

}


void MainWindow_Universe::on_actionOpen_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, "Open a file");
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this,"Error",file.errorString());
        return;
    }
    QTextStream stream(&file);
    ui->plainTextEdit->setPlainText(stream.readAll());
    file.close();
    ui->statusbar->showMessage(path);
    m_filename = path;

}


void MainWindow_Universe::on_actionSave_triggered()
{

}


void MainWindow_Universe::on_actionCopy_triggered()
{

}


void MainWindow_Universe::on_actionPaste_triggered()
{

}


void MainWindow_Universe::on_actionCut_triggered()
{

}


void MainWindow_Universe::on_actionSelect_All_triggered()
{

}

