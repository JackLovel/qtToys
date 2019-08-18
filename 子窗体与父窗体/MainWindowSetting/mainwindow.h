#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/***
    子窗体传值给父窗体
*/
#include "settingdialog.h"

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void receiveData(QString data); // 接收传递过来的数据 slots

private:
    QWidget *mainWidget;
    SettingDialog settingDialog;
    QHBoxLayout *mainLayout;

//    QLabel *label;
    QTextEdit *textEdit;
};

#endif // MAINWINDOW_H
