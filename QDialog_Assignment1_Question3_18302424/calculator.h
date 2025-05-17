// 18302424
// COS3711 Assignment 1 Question 3
// Program written by Kutlwano Ndumiso Mahlangu


#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QDialog>
#include <QString>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class Calculator : public QDialog
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

    void Handle_Overflow_QLCDNumber();

    // Global variables.
    float Number1 = 0;
    float Number2 = 0;
    QString OutputLineEdit = " ";
    float Result = 0;
    QString OutputLCD = " ";

private slots:
    void on_pushButtonAddition_clicked();

    void on_pushButtonMinus_clicked();

    void on_pushButtonMultiply_clicked();

    void on_pushButtonDivision_clicked();

    void on_pushButtonClear_clicked();

private:
    Ui::Calculator *ui;
};
#endif // CALCULATOR_H
