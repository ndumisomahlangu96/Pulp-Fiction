#include "dialog1.h"
#include "./ui_dialog1.h"

Dialog1::Dialog1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog1)
{
    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_buttonBox_accepted()
{
    QMessageBox::information(this,"Selected","You have selected: \r\n " + ui->lineEdit->text());
    accept();
}


void Dialog1::on_buttonBox_rejected()
{

    reject();
}


void Dialog1::on_pushButtonSelect_clicked()
{
    // Create a pointer to manage memory for selections dialog.
    Selections *dlg = new Selections(this);

    // Set the default.
    dlg->setSelected(ui->lineEdit->text());

    // Exec (show on screen) the dialog
    dlg->exec();

    // Read back the new selection
    ui->lineEdit->setText(dlg->selected());

}

