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

void Dialog1::on_pushButtonWithParent_clicked()
{
    // With Parent
    Dialog2 *dialog = new Dialog2(this);
    dialog->show();
}


void Dialog1::on_pushButtonWithoutParent_clicked()
{
    // Without Parent
    Dialog2 *dialog = new Dialog2(nullptr);
    dialog->show();
}

