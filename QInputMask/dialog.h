#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>                      // The QMessageBox class provides a modal dialog for informing the user or for asking the user a question and receiving an answer.
#include <QRegularExpression>               // The QRegularExpression class provides pattern matching using regular expressions.
#include <QRegularExpressionValidator>      // he QRegularExpressionValidator class is used to check a string against a regular expression.

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void checkInput();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
