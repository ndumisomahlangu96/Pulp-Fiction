// 18302424
// COS3711 Assignment 1 Question 2
// Program written by Kutlwano Ndumiso Mahlangu

#ifndef BANKINGTRANSACTIONS_H
#define BANKINGTRANSACTIONS_H

#include <QDialog>          // The QDialog class is the base class of dialog windows.
#include <QDate>            // The QDate class provides date functions.
#include <QDateTime>        // The QDateTime class provides date and time functions.
#include <QDebug>           // The QDebug class provides an output stream for debugging information.
#include <QFile>            // The QFile class provides an interface for reading from and writing to files.
#include <QTextStream>      // The QTextStream class provides a convenient interface for reading and writing text.
#include <QDoubleValidator> // The QDoubleValidator class provides range checking of floating-point numbers.
#include <QLocale>          // The QLocale class converts between numbers and their string representations in various languages.

QT_BEGIN_NAMESPACE
namespace Ui {
class BankingTransactions;
}
QT_END_NAMESPACE

class BankingTransactions : public QDialog
{
    Q_OBJECT

public:
    BankingTransactions(QWidget *parent = nullptr);
    ~BankingTransactions();

private slots:
    void on_pushButtonDeposit_clicked();

    void on_pushButtonFile_clicked();

    void on_pushButtonWithdrawal_clicked();

    void on_pushButtonEmptyFile_clicked();

private:
    Ui::BankingTransactions *ui;
    QDoubleValidator *validator;
};
#endif // BANKINGTRANSACTIONS_H
