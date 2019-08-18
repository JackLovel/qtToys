#include "settingdialog.h"

#include <QComboBox>

SettingDialog::SettingDialog(QWidget *parent) : QDialog(parent)
{
    lineEdit = new QLineEdit(this);
    okBtn = new QPushButton(tr("ok"));

    mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(lineEdit);
    mainLayout->addWidget(okBtn);

    connect(okBtn, &QPushButton::clicked, this, &SettingDialog::on_pushButton_clicked);

    setFixedSize(500, 500);
    setLayout(mainLayout);
}


SettingDialog::~SettingDialog() {

}

void SettingDialog::on_pushButton_clicked() {
    emit sendData(lineEdit->text()); // 获取lineEdit的输入并且传递出去
}
