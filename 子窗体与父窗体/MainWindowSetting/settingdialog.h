#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QApplication>
#include <QDialog>
#include <QHBoxLayout>
#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    SettingDialog(QWidget *parent = 0);
    ~SettingDialog();

private slots:
    void on_pushButton_clicked();

signals:
    void sendData(QString); // 用来传递信号

private:
    QLineEdit *lineEdit;
    QPushButton *okBtn;

    QHBoxLayout *mainLayout;
};

#endif // SETTINGDIALOG_H
