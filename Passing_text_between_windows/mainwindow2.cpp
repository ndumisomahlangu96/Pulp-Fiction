#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include <QLabel> // Include QLabel if you haven't already through ui_mainwindow2.h

MainWindow2::MainWindow2(const QString &customerName, QWidget *parent) // Modified constructor
    : QMainWindow(parent)
    , ui(new Ui::MainWindow2)
    , m_customerName(customerName) // Initialize m_customerName with the passed value
{
    ui->setupUi(this);
    // Assuming you have a QLabel named 'label' in your MainWindow2 UI
    ui->label->setText(m_customerName); // Set the text of the QLabel
}

MainWindow2::~MainWindow2()
{
    delete ui;
}
