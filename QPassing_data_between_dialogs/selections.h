#ifndef SELECTIONS_H
#define SELECTIONS_H

#include <QDialog>
#include <QDir>                 // The QDir class provides access to directory structures and their contents.
#include <QFile>                // The QFile class provides an interface for reading from and writing to files.
#include <QFileInfo>            // The QFileInfo class provides an OS-independent API to retrieve information about file system entries.
#include <QFileInfoList>
#include <QListWidgetItem>      // The QListWidgetItem class provides an item for use with the QListWidget item view class.
#include <QString>              // The QString class provides a Unicode character string.

namespace Ui {
class Selections;
}

class Selections : public QDialog
{
    Q_OBJECT

public:
    explicit Selections(QWidget *parent = nullptr);
    ~Selections();

    QString selected();
    void setSelected(QString value);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Selections *ui;

    QString m_selected;
    void init();
};

#endif // SELECTIONS_H
