#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButtonCancel_clicked()
{
    reject();  // Will close the app.
}


void Dialog::on_pushButtonOk_clicked()
{
    QString toppings;
    QObjectList boxes = this->children();
    foreach (QObject* obj, boxes)
    {
        if (obj->inherits("QCheckBox"))
        {
            QCheckBox* box = qobject_cast<QCheckBox*>(obj);
            if (box && box->isChecked())
            {
                toppings += box->text() + "\r\n";
            }
        }
    }

    // Output to the user.
    QMessageBox::information(this, "Toppings", "Toppings to include \r\n" + toppings);
    accept(); // Will close the app.
}

