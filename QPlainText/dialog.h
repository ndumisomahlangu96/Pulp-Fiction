#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>                  // The QPushButton widget provides a command button.
#include <QPlainTextEdit>               // The QPlainTextEdit class provides a widget that is used to edit and display plain text.
#include <QMessageBox>                  // The QMessageBox class provides a modal dialog for informing the user or for asking the user a question and receiving an answer.
#include <QFile>                        // The QFile class provides an interface for reading from and writing to files.
#include <QTextStream>                  // The QTextStream class provides a convenient interface for reading and writing text.

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

    void load();
    void save();
    void on_plainTextEdit_textChanged();
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Dialog *ui;
    bool m_saved;

// QWidget interface.
protected:
    void closeEvent(QCloseEvent *event) override;
};
#endif // DIALOG_H
