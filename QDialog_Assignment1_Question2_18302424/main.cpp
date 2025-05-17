// 18302424
// COS3711 Assignment 1 Question 2
// Program written by Kutlwano Ndumiso Mahlangu

#include "bankingtransactions.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BankingTransactions w;
    w.show();
    return a.exec();
}
