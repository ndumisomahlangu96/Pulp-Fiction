// 18302424
// COS3711 Assignment 1 Question 3
// Program written by Kutlwano Ndumiso Mahlangu

#include "calculator.h"
#include "./ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Calculator)
{
    // Setup frontend of Calculator App.
    ui->setupUi(this);
    ui->doubleSpinBoxNumber1->setValue(0);
    ui->doubleSpinBoxNumber2->setValue(0);

}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::Handle_Overflow_QLCDNumber()
{

    // Calculate required digits
    int integerDigits = floor(log10(fabs(Result))) + 1;
    int totalDigits = integerDigits + 3; // +3 for decimal point and 2 decimals

    if (totalDigits > ui->lcdNumber->digitCount()) {
        // Handle overflow
        ui->lcdNumber->display("Err");
    } else {
        ui->lcdNumber->display(OutputLCD);
    }
}

void Calculator::on_pushButtonAddition_clicked()
{
    Number1 = ui->doubleSpinBoxNumber1->value();
    Number2 = ui->doubleSpinBoxNumber2->value();
    Result = Number1 + Number2;
    OutputLCD = QString::number(Result);    // Float to QString

    Handle_Overflow_QLCDNumber(); // Call function to handle overflow in QLCDNumber display appropriately.

    // Output the equation of the addition of the two numbers to the users.
    OutputLineEdit = QString::number(Number1) + " + " + QString::number(Number2) + " = " + QString::number(Result);
    ui->lineEdit->setText(OutputLineEdit);

}


void Calculator::on_pushButtonMinus_clicked()
{
    Number1 = ui->doubleSpinBoxNumber1->value();
    Number2 = ui->doubleSpinBoxNumber2->value();
    Result = Number1 - Number2;
    OutputLCD = QString::number(Result);    // Float to QString

    Handle_Overflow_QLCDNumber(); // Call function to handle overflow in QLCDNumber display appropriately.

    // Output the equation of the subtraction of the two numbers to the users.
    OutputLineEdit = QString::number(Number1) + " - " + QString::number(Number2) + " = " + QString::number(Result);
    ui->lineEdit->setText(OutputLineEdit);
}


void Calculator::on_pushButtonMultiply_clicked()
{
    Number1 = ui->doubleSpinBoxNumber1->value();
    Number2 = ui->doubleSpinBoxNumber2->value();
    Result = Number1 * Number2;
    OutputLCD = QString::number(Result);    // Float to QString

    Handle_Overflow_QLCDNumber(); // Call function to handle overflow in QLCDNumber display appropriately.

    // Output the equation of the multiplication of the two numbers to the users.
    OutputLineEdit = QString::number(Number1) + " * " + QString::number(Number2) + " = " + QString::number(Result);
    ui->lineEdit->setText(OutputLineEdit);
}


void Calculator::on_pushButtonDivision_clicked()
{
    Number1 = ui->doubleSpinBoxNumber1->value();
    Number2 = ui->doubleSpinBoxNumber2->value();

    // Handle division by 0 appropriately.
    if (Number2 == 0)
    {
        QMessageBox::critical(this, "Critical Error", "Division by zero is undefined(no solution).",QMessageBox::Ok);
    }
    else
    {
        Result = Number1 / Number2;
        OutputLCD = QString::number(Result);    // Float to QString

        Handle_Overflow_QLCDNumber(); // Call function to handle overflow in QLCDNumber display appropriately.

        // Output the equation of the division of the two numbers to the users.
        OutputLineEdit = QString::number(Number1) + " / " + QString::number(Number2) + " = " + QString::number(Result);
        ui->lineEdit->setText(OutputLineEdit);

    }

}


void Calculator::on_pushButtonClear_clicked()
{
    // The button clear is used to clear QDoubleSpinBoxes and QLCDNumber.
    ui->doubleSpinBoxNumber1->setValue(0);
    ui->doubleSpinBoxNumber2->setValue(0);
    ui->lcdNumber->display("0");
    ui->lineEdit->setText(" ");
}

