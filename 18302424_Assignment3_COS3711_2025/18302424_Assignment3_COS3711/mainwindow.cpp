#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Set the initial tab to tab_2
    ui->tabWidget->setCurrentWidget(ui->tab_2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// To display output from a backend logic to the frontend user interface(ui).
void MainWindow::on_pushButtonBox_clicked()
{
    // Process input volume data for Box.
    int breadth = ui->spinBoxBreadthBox->value();
    int length = ui->spinBoxLengthBox->value();
    int heightBox = ui->spinBoxHeightBox->value();
    int weightBox = ui->spinBoxWeightBox->value();

    // Calculate the volume of the Box.
    BoxVolume = breadth*length*heightBox;

    // Process input volume data for Cylinder Box.
    int diameter = ui->spinBoxDiameterCylinder->value();
    int heightCylinder = ui->spinBoxHeightCylinder->value();
    int weightCylinder = ui->spinBoxWeightCylinder->value();

    // Calculate the volume of the Cylinder.
    CylinderVolume = M_PI * (diameter/2) * heightCylinder;

    // Calculate the total volume of both objects.
    TotalVolume = BoxVolume + CylinderVolume;

    // Calculate the total weight of both objects.
    TotalWeight = weightBox + weightCylinder;

    // BoxData = QString::number(value);
    QString BoxData = "Total Volume: " + QString::number(TotalVolume)+ " cubic meters(m³),"+"Total Weight: " + QString::number(TotalWeight) + " kilograms(kg).";

    ui->listWidget->addItem(BoxData);
}

void MainWindow::on_pushButtonClear_clicked()
{
    ui->spinBoxBreadthBox->setValue(0);
    ui->spinBoxDiameterCylinder->setValue(0);
    ui->spinBoxHeightBox->setValue(0);
    ui->spinBoxHeightCylinder->setValue(0);
    ui->spinBoxLengthBox->setValue(0);
    ui->spinBoxWeightBox->setValue(0);
    ui->spinBoxWeightCylinder->setValue(0);
    ui->listWidget->clear();
}

void MainWindow::on_pushButtonCylinder_clicked()
{
    // Process input volume data for Box.
    int breadth = ui->spinBoxBreadthBox->value();
    int length = ui->spinBoxLengthBox->value();
    int heightBox = ui->spinBoxHeightBox->value();
    int weightBox = ui->spinBoxWeightBox->value();

    // Calculate the volume of the Box.
    BoxVolume = breadth*length*heightBox;

    // Process input volume data for Cylinder Box.
    int diameter = ui->spinBoxDiameterCylinder->value();
    int heightCylinder = ui->spinBoxHeightCylinder->value();
    int weightCylinder = ui->spinBoxWeightCylinder->value();

    // Calculate the volume of the Cylinder.
    CylinderVolume = M_PI * (diameter/2) * heightCylinder;

    // Calculate the total volume of both objects.
    TotalVolume = BoxVolume + CylinderVolume;

    // Calculate the total weight of both objects.
    TotalWeight = weightBox + weightCylinder;

    // BoxData = QString::number(value);
    QString BoxData = "Total Volume: " + QString::number(TotalVolume)+ " cubic meters(m³),"+"Total Weight: " + QString::number(TotalWeight) + " kilograms(kg).";

    ui->listWidget->addItem(BoxData);
}

/*
 * Backend logic to the container code
 * Which is allocated when cotainers are created, takes the following format.
 * YYYY/MM/ContainerType
 */
void MainWindow::on_pushButtonCode_clicked()
{
    // Process input data for Container Code.
    int year = ui->spinBoxYear->value();
    int month = ui->spinBoxMonth->value();
    QString monthString;
    QString ContainerType = ui->comboBoxContainer->currentText();

    // Process month data into the correct format of MM from spinBoxMonth.
    if (month < 10)
    {
        monthString = "0" + QString::number(month);
    }
    else
    {
        monthString = QString::number(month);
    }

    serialnumber = serialnumber + 1;

    ContainerCode = QString::number(year)+ "/" + monthString + "/" + ContainerType + QString::number(serialnumber);
    ui->listWidgetCode->addItem(ContainerCode);
}

void MainWindow::initialize()
{
    ui->comboBoxContainer->setEnabled(true);
}

void MainWindow::load()
{
    QSettings settings("ContainerCompany","AppData");

    int listsize = settings.beginReadArray("list");
    for (int i = 0; i < listsize; i++)
    {
        settings.setArrayIndex(i);
        ui->listWidgetCode->addItem(settings.value("data","").toString());
    }
    settings.endArray();
}

void MainWindow::save()
{
    QSettings settings("ContainerCompany","AppData");
    settings.clear();

    settings.setValue("text",ContainerCode);

    settings.beginWriteArray("list");
    for (int i = 0; i < ui->listWidgetCode->count(); ++i)
    {
        settings.setArrayIndex(i);
        settings.setValue("data",ui->listWidgetCode->item(i)->text());
    }
    settings.endArray();
}

void MainWindow::on_pushButtonSave_clicked()
{
    save();
    qInfo() << "Successfully saved data to the storage drive.";
}

void MainWindow::on_pushButtonLoad_clicked()
{
    load();
    qInfo() << "Successfully restored data saved on the storage drive.";
}

void MainWindow::on_pushButtonRemove_clicked()
{
    QList<QListWidgetItem*> items = ui->listWidgetCode->selectedItems();
    foreach (QListWidgetItem* item, items)
    {
        ui->listWidgetCode->removeItemWidget(item);
        delete item;
    }
}

void MainWindow::on_pushButtonClear_2_clicked()
{
    ui->listWidgetCode->clear();
}


void MainWindow::on_pushButtonClose_clicked()
{
    save();
    qInfo() << "Successfully saved data to the storage drive.";
    close();
}
