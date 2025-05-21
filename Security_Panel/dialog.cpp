#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    // Setup frontend(UI- User Interface)
    ui->setupUi(this);
    if (code.isEmpty())
    {
        ui->pushButton_Save->setEnabled(true);
        ui->pushButton_Verify->setEnabled(false);
    }
    else
    {
        ui->pushButton_Save->setEnabled(false);
        ui->pushButton_Verify->setEnabled(true);
    }
    connect(ui->pushButton_0,&QPushButton::clicked,this,&Dialog::append);
    connect(ui->pushButton_1,&QPushButton::clicked,this,&Dialog::append);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&Dialog::append);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&Dialog::append);
    connect(ui->pushButton_4,&QPushButton::clicked,this,&Dialog::append);
    connect(ui->pushButton_5,&QPushButton::clicked,this,&Dialog::append);
    connect(ui->pushButton_6,&QPushButton::clicked,this,&Dialog::append);
    connect(ui->pushButton_7,&QPushButton::clicked,this,&Dialog::append);
    connect(ui->pushButton_8,&QPushButton::clicked,this,&Dialog::append);
    connect(ui->pushButton_9,&QPushButton::clicked,this,&Dialog::append);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::append()
{
    QPushButton* btn = qobject_cast<QPushButton*> (sender());
    if (!btn) {
        return;
    }

    temp.append(btn->text());
    ui->label_Notify->setText("Typed: " + temp);
}

// Reset the frontend(UI - User Interface) to default settings.
void Dialog::on_pushButtonClear_clicked()
{
    ui->label_Notify->setText("Please enter a code and press save");
    ui->pushButton_Save->setEnabled(true);
    ui->pushButton_Verify->setEnabled(false);


}

void Dialog::on_pushButton_Save_clicked()
{
    code = temp;
    temp.clear();
    ui->pushButton_Save->setEnabled(false);
    ui->pushButton_Verify->setEnabled(true);
}
