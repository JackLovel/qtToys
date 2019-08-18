#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    textEdit = new QTextEdit(this);
    SettingDialog *dlg = new SettingDialog;
    connect(dlg, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
    dlg->show();

    setCentralWidget(textEdit);
}

MainWindow::~MainWindow()
{

}

void MainWindow::receiveData(QString data)
{
    textEdit->setText(data);
}



