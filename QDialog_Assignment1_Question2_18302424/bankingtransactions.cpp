// 18302424
// COS3711 Assignment 1 Question 2
// Program written by Kutlwano Ndumiso Mahlangu

#include "bankingtransactions.h"
#include "./ui_bankingtransactions.h"

BankingTransactions::BankingTransactions(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BankingTransactions)
{
    // Setup(default values) the frontend of banking transactions app.
    ui->setupUi(this);
    ui->label_3->setText(QDate::currentDate().toString());
    ui->labelAmount->setText("Amount R:");
    ui->lineEditAmount->setPlaceholderText("Enter a decimal number (123.45)");

    // Create and configure the validator
    validator = new QDoubleValidator(this);
    validator->setNotation(QDoubleValidator::StandardNotation);  // Standard decimal notation
    validator->setDecimals(2);  // Allow up to 6 decimal places
    validator->setLocale(QLocale::c());  // Force '.' as decimal separator

    ui->lineEditAmount->setValidator(validator);
}

BankingTransactions::~BankingTransactions()
{
    delete ui;
}

void BankingTransactions::on_pushButtonDeposit_clicked()
{
    // Create a QFile object for the file we want to write to
    QFile file("TransactionsData.txt");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        qDebug() << "Could not open file for writing!";

    }

    qDebug() << "++++++++++++";

    // Create a QTextStream to write to the file
    QTextStream out(&file);

    out << "Desposit: +R" << ui->lineEditAmount->text() << "on" << QDateTime::currentDateTime().toString();
    // Flush the stream to ensure all data is written
    out.flush();

    qDebug() << "Desposit: +R" << ui->lineEditAmount->text() << "on" << QDateTime::currentDateTime().toString();

    // Close the file when done
    file.close();

    qDebug() << "Transaction data written successfully to textfile!";
}


void BankingTransactions::on_pushButtonFile_clicked()
{
    // Create a QFile object for the file you want to read
    QFile file("TransactionsData.txt");

    // Try to open the file in read-only mode
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Could not open file!";
    }

    // Create a QTextStream to read from the file
    QTextStream in(&file);

    // Output to the console.
    qDebug() << "===============";
    qDebug() << "Financial log:";

    // Read the file line by line and output to console
    while (!in.atEnd())
    {
        QString line = in.readLine();
        qDebug() << line;
    }

    // Close the file when done
    file.close();
}


void BankingTransactions::on_pushButtonWithdrawal_clicked()
{
    // Create a QFile object for the file we want to write to
    QFile file("TransactionsData.txt");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        qDebug() << "Could not open file for writing!";

    }

    qDebug() << "--------------";

    // Create a QTextStream to write to the file
    QTextStream out(&file);

    out << "Withdrawal: -R" << ui->lineEditAmount->text() <<  "on" << QDateTime::currentDateTime().toString();
    // Flush the stream to ensure all data is written
    out.flush();

    qDebug() << "Withdrawal: -R" << ui->lineEditAmount->text() << "on" << QDateTime::currentDateTime().toString();

    // Close the file when done
    file.close();

    qDebug() << "Transaction data written successfully to textfile!";
}


void BankingTransactions::on_pushButtonEmptyFile_clicked()
{
    QFile file("TransactionsData.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        // File is now empty
        qDebug() << "==========================================";
        qDebug() << "Successfully reset(cleared) financial log!";
        file.close();
    } else {
        qDebug() << "==========================================";
        qDebug() << "Failed to reset(emptied) financial log!" << file.errorString();
    }
}

