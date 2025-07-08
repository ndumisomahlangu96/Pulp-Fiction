#include "mainwindow1.h"
#include "ui_mainwindow1.h"

MainWindow1::MainWindow1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow1)
{
    ui->setupUi(this);
}

MainWindow1::~MainWindow1()
{
    delete ui;
}

void MainWindow1::on_pushButton_clicked()
{
    // Get the text from the QLineEdit in MainWindow1
    QString customerName = ui->lineEdit->text();

    // Create a MainWindow2 instance and pass the customerName to its constructor
    MainWindow2 *main = new MainWindow2(customerName, this); // Pass customerName and parent
    main->show();
}

