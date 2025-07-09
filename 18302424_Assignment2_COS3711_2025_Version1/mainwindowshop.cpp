#include "mainwindowshop.h"
#include "ui_mainwindowshop.h"

MainWindowShop::MainWindowShop(const QString &customerName, QWidget *parent )   // Modified constructor
    : QMainWindow(parent)
    , ui(new Ui::MainWindowShop)
    , m_customerName(customerName) // Initialize m_customerName with the passed value.
{
    ui->setupUi(this);

    // Setup the default frontend(user interaction) of mainwindowshop.
    ui->labelCustomerName->setText(m_customerName);
    //ui->labelDateTime->setText(QDateTime::currentDateTime().toString());
    // Initialize the QTimer.
    timer = new QTimer(this);

    // Connect the timer's timeout signal to our updateDateTime slot.
    connect(timer, &QTimer::timeout, this, &MainWindowShop::updateDateTime);

    // Start the timer to update every 1000 milliseconds (1 second).
    timer->start(1000);

    // Call it once immediately to show the time when the window opens.
    updateDateTime();

    // Connections signals and slots of mainwindowshop.
    // Functions to close the App.
    connect(ui->actionExit,&QAction::triggered,this,&MainWindowShop::close);

    // Functions to setup the Toolbar.
    connect(ui->actionToolbar_top,&QAction::triggered,this,&MainWindowShop::actionToolbarTop);
    connect(ui->actionToolbar_bottom,&QAction::triggered,this,&MainWindowShop::actionToolbarBottom);
    connect(ui->actionToolbar_right,&QAction::triggered,this,&MainWindowShop::actionToolbarRight);
    connect(ui->actionToolbar_left,&QAction::triggered,this,&MainWindowShop::actionToolbarLeft);

    // Functions to control the text file used to store items.
    connect(ui->actionNew_File,&QAction::triggered,this,&MainWindowShop::newFile);
    connect(ui->actionSave_File,&QAction::triggered,this,&MainWindowShop::saveFile);
    connect(ui->actionOpen_File,&QAction::triggered,this,&MainWindowShop::openFile);

    // Functions used to edit plain text.
    connect(ui->actionCopy, &QAction::triggered,ui->plainTextEdit, &QPlainTextEdit::copy);
    connect(ui->actionCut, &QAction::triggered,ui->plainTextEdit, &QPlainTextEdit::cut);
    connect(ui->actionPaste, &QAction::triggered,ui->plainTextEdit, &QPlainTextEdit::paste);
    connect(ui->actionSelect_All, &QAction::triggered,ui->plainTextEdit, &QPlainTextEdit::selectAll);
    connect(ui->actionSelect_None, &QAction::triggered,this, &MainWindowShop::selectNone);

}

MainWindowShop::~MainWindowShop()
{
    delete ui;
}

void MainWindowShop::setupStatusbar()
{
    QLabel *lblIcon = new QLabel(this);
    lblIcon->setPixmap(QPixmap(":/files/images/new.png"));
    ui->statusbar->addWidget(lblIcon);

    QLabel *lblStatus = new QLabel(this);
    lblStatus->setText("Not Saved:");
    ui->statusbar->addWidget(lblStatus);

    QLabel *lblFile = new QLabel(this);
    lblFile->setText("New");
    ui->statusbar->addWidget(lblFile);
}

void MainWindowShop::actionToolbarTop()
{
    addToolBar(Qt::ToolBarArea::TopToolBarArea,ui->toolBar);
}

void MainWindowShop::actionToolbarRight()
{
    addToolBar(Qt::ToolBarArea::RightToolBarArea,ui->toolBar);
}

void MainWindowShop::actionToolbarLeft()
{
    addToolBar(Qt::ToolBarArea::LeftToolBarArea,ui->toolBar);
}

void MainWindowShop::actionToolbarBottom()
{
    addToolBar(Qt::ToolBarArea::BottomToolBarArea,ui->toolBar);
}

void MainWindowShop::on_actionToolbar_movable_toggled(bool arg1)
{
    ui->toolBar->setMovable(arg1);
}

void MainWindowShop::on_actionToolbar_floatable_toggled(bool arg1)
{
    ui->toolBar->setFloatable(arg1);
}

void MainWindowShop::newFile()
{
    ui->plainTextEdit->clear();
    m_filename.clear();
    m_saved = false;
    ui->statusbar->showMessage("New File");

}

void MainWindowShop::openFile()
{
    QString temp = QFileDialog::getOpenFileName(this,"Open File",QString(),"Text Files (*.txt);;All Files (*,*)");

    if(temp.isEmpty()) return;

    m_filename = temp;
    QFile file(m_filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        newFile();
        QMessageBox::critical(this,"Error", file.errorString());
        return;
    }

    QTextStream stream(&file);
    ui->plainTextEdit->setPlainText(stream.readAll());
    file.close();

    m_saved = true;
    ui->statusbar->showMessage(m_filename);
}

void MainWindowShop::saveFile()
{
    if(m_filename.isEmpty())
    {
        saveFileAs();
        return;
    }

    QFile file(m_filename);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this,"Error", file.errorString());
        return;
    }

    QTextStream stream(&file);
    stream << ui->plainTextEdit->toPlainText();
    file.close();

    m_saved = true;
    ui->statusbar->showMessage(m_filename);

}

void MainWindowShop::saveFileAs()
{
    QString temp = QFileDialog::getSaveFileName(this,"Save File",QString(),"Text Files (*.txt);;All Files (*,*)");
    if(temp.isEmpty()) return;
    m_filename = temp;
    saveFile();
}

void MainWindowShop::selectNone()
{
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    int pos = cursor.position();
    cursor.clearSelection();
    cursor.setPosition(pos,QTextCursor::MoveMode::KeepAnchor);
    ui->plainTextEdit->setTextCursor(cursor);
}

void MainWindowShop::on_pushButtonCloseApp_clicked()
{
    saveFile();
    MainWindowShop::close();
}

void MainWindowShop::transferLabelText()
{
    // Get text from QLabel.
    QString labelTextName = ui->labelCustomerName->text();
    QString labelTextDate = ui->labelDateTime->text();

    // Append the text to QPlainTextEdit, ensuring a new line.
    // appendPlainText automatically adds a newline before appending its argument.
    ui->plainTextEdit->appendPlainText(labelTextName);
    ui->plainTextEdit->appendPlainText(labelTextDate);
}

void MainWindowShop::transferComboBoxText()
{
    // Get the currently selected text from the QComboBox.
    QString selectedTextType = ui->comboBoxType->currentText();
    QString selectedTextSize = ui->comboBoxSize->currentText();

    // Append the text to QPlainTextEdit, which automatically adds a newline.
    ui->plainTextEdit->appendPlainText(selectedTextType);
    ui->plainTextEdit->appendPlainText(selectedTextSize);
}

void MainWindowShop::transferSpinBoxValue()
{
    // Get the current integer value from the QSpinBox.
    int spinBoxValue = ui->spinBox->value();

    // Convert the integer to a QString to append to QPlainTextEdit.
    QString valueString = QString::number(spinBoxValue);

    // Append the string to QPlainTextEdit, which automatically adds a newline.
    ui->plainTextEdit->appendPlainText(valueString);
}

void MainWindowShop::headingText()
{
    ui->plainTextEdit->appendPlainText("**************");
    ui->plainTextEdit->appendPlainText("*Transaction*");
    ui->plainTextEdit->appendPlainText("**************");
}

void MainWindowShop::updateDateTime()
{
    // Update the QLabel with the current date and time.
    // ui->labelDateTime is assumed to be the name of your QLabel from the UI file.
    ui->labelDateTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
}

void MainWindowShop::on_pushButtonAdd_clicked()
{
    headingText();
    transferLabelText();        // Get text from QLabel.
    transferComboBoxText();     // Get the currently selected text from the QComboBox.
    transferSpinBoxValue();     // Get the current integer value from the QSpinBox.
}

