#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include "dialog2.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog1;
}
QT_END_NAMESPACE

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    Dialog1(QWidget *parent = nullptr);
    ~Dialog1();

private slots:
    void on_pushButtonWithParent_clicked();

    void on_pushButtonWithoutParent_clicked();

private:
    Ui::Dialog1 *ui;
};
#endif // DIALOG1_H
