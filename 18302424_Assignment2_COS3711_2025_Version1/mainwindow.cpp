#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->AddItempushButton,&QPushButton::clicked,this,&MainWindow::AddItempushButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddItempushButton()
{
    // Get the text from the QLineEdit in MainWindow.
    QString customerName = ui->lineEdit->text();

    // Create a MainWindowShop instance and pass the customerName to its constructor.
    MainWindowShop *maindwindowChooseItem = new MainWindowShop(customerName,this);
    // Shows the widget and its child widgets.
    maindwindowChooseItem->show();
}


