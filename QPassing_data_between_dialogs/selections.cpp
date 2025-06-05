#include "selections.h"
#include "ui_selections.h"

Selections::Selections(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Selections)
{
    ui->setupUi(this);
    init();
}

Selections::~Selections()
{
    delete ui;
}

QString Selections::selected()
{
    return m_selected;
}

void Selections::setSelected(QString value)
{
    m_selected = " ";

    for (int var = 0; var < ui->listWidget->count(); ++var)
    {
        QListWidgetItem *itm = ui->listWidget->item(var);
        if (itm->text() == value)
        {
            itm->setSelected(true);     // Sets the selected state of the item to select.
            m_selected = value;
            return;
        }
    }
}

void Selections::on_buttonBox_accepted()
{
    if (ui->listWidget->currentItem())
    {
        m_selected = ui->listWidget->currentItem()->text();
    }
    accept();
}


void Selections::on_buttonBox_rejected()
{
    reject();
}

void Selections::init()
{
    QDir root = QDir(":/file/images");
    QFileInfoList list = root.entryInfoList();
    foreach (QFileInfo fi,list)
    {
        QListWidgetItem *itm = new QListWidgetItem(ui->listWidget);
        itm->setText(fi.absoluteFilePath());
        itm->setIcon(QIcon(fi.absoluteFilePath()));
        ui->listWidget->addItem(itm);
    }
}

