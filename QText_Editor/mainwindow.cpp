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
    connect(ui->actionOpen,&QAction::triggered,this,&MainWindow::openFile);
    connect(ui->actionSave,&QAction::triggered,this,&MainWindow::saveFile);
    connect(ui->actionSave_As,&QAction::triggered,this,&MainWindow::saveFileAs);




    newFile();
    m_saved = true;

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
    QString temp = QFileDialog::getOpenFileName(this,"Open File",QString(),"Text Files(*txt);; All Files(*,*)");
    if (temp.isEmpty()) return;

    m_filename = temp;
    QFile file(m_filename);
    if (!file.open(QIODevice::ReadOnly))
    {
        newFile();
        QMessageBox::critical(this,"Error",file.errorString());
        return;
    }

    QTextStream stream(&file);
    ui->plainTextEdit->setPlainText(stream.readAll());
    file.close();

    m_saved = true;
    ui->statusbar->showMessage(m_filename);
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
