#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Validate the input from the user for email address.
    QRegularExpression rxEmail("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",QRegularExpression::CaseInsensitiveOption);
    ui->lineEditEmail->setValidator(new QRegularExpressionValidator(rxEmail,this));

    // Validate the input from the user for phone.
    QRegularExpression rxPhone("^0(([- .]?)\\d){9}$",QRegularExpression::CaseInsensitiveOption);
    ui->lineEditPhone->setValidator(new QRegularExpressionValidator(rxPhone,this));

    // Validate the input from the user for IP address.
    QRegularExpression rxIP("^(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])(\\.(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])){3}$",
                            QRegularExpression::CaseInsensitiveOption);
    ui->lineEditIP->setValidator(new QRegularExpressionValidator(rxIP,this));

    // Validate the input from the user for date.
    QRegularExpression rxDate("^(?:(?:19|20)(?:[02468][048]|[13579][26])|2000)-02-29|(?:19|20)\\d{2}-(?:(?:0[13578]|1[02])-(?:0[1-9]|[12]\\d|3[01])|(?:0[469]|11)-(?:0[1-9]|[12]\\d|30)|02-(?:0[1-9]|1\\d|2[0-8]))$",
                              QRegularExpression::CaseInsensitiveOption);
    ui->lineEditDate->setValidator(new QRegularExpressionValidator(rxDate,this));

    // Signals and slots for the UI.
    connect(ui->lineEditEmail,&QLineEdit::textChanged,this,&Dialog::checkInput);
    connect(ui->lineEditPhone,&QLineEdit::textChanged,this,&Dialog::checkInput);
    connect(ui->lineEditIP,&QLineEdit::textChanged,this,&Dialog::checkInput);
    connect(ui->lineEditDate,&QLineEdit::textChanged,this,&Dialog::checkInput);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    if (ui->lineEditEmail->hasAcceptableInput())
    {
        QMessageBox::information(this,"User Email",ui->lineEditEmail->text());
        accept();
    }
    else
    {
        QMessageBox::critical(this,"Email","Not valid!");
    }

    if (ui->lineEditPhone->hasAcceptableInput())
    {
        QMessageBox::information(this,"User Phone",ui->lineEditPhone->text());
        accept();
    }
    else
    {
        QMessageBox::critical(this,"Phone","Not valid!");
    }

    if (ui->lineEditIP->hasAcceptableInput())
    {
        QMessageBox::information(this,"User IP address",ui->lineEditIP->text());
        accept();
    }
    else
    {
        QMessageBox::critical(this,"IP address","Not valid!");
    }

    if (ui->lineEditDate->hasAcceptableInput())
    {
        QMessageBox::information(this,"User Date",ui->lineEditPhone->text());
        accept();
    }
    else
    {
        QMessageBox::critical(this,"Date","Not valid!");
    }
}


void Dialog::on_buttonBox_rejected()
{
    reject();
}

void Dialog::checkInput()
{
    if (ui->lineEditEmail->hasAcceptableInput())
    {
        ui->lineEditEmail->setStyleSheet("QLineEdit {color : black}");
    }
    else
    {
        ui->lineEditEmail->setStyleSheet("QLineEdit {color : red}");
    }

    if (ui->lineEditPhone->hasAcceptableInput())
    {
        ui->lineEditPhone->setStyleSheet("QLineEdit {color : black}");
    }
    else
    {
        ui->lineEditPhone->setStyleSheet("QLineEdit {color : red}");
    }

    if (ui->lineEditIP->hasAcceptableInput())
    {
        ui->lineEditIP->setStyleSheet("QLineEdit {color : black}");
    }
    else
    {
        ui->lineEditIP->setStyleSheet("QLineEdit {color : red");
    }

    if (ui->lineEditDate->hasAcceptableInput())
    {
        ui->lineEditDate->setStyleSheet("QLineEdit {color : black}");
    }
    else
    {
        ui->lineEditDate->setStyleSheet("QLineEdit {color : red}");
    }
}

