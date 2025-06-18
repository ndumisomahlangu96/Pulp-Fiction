#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Setup frontend of Text Editor App.
    ui->setupUi(this);
    this->setCentralWidget(ui->plainTextEdit);

    // Signals and slots.
    connect(ui->actionNew,&QAction::triggered,this,&MainWindow::newFile);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile()
{
    ui->plainTextEdit->clear();
    m_filename.clear();
    m_saved = false;
    ui->statusbar->showMessage("New File");
}

void MainWindow::openFile()
{

}

void MainWindow::saveFile()
{

}

void MainWindow::saveFileAs()
{

}

void MainWindow::SelectNone()
{

}
