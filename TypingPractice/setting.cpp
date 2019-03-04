#include "setting.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDebug>
#include <QPushButton>
#include <QMessageBox>

Setting::Setting(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout *layout = new QVBoxLayout;


    QString content = readJson();
    testLabel = new QLabel(content, this);

    resize(300, 300);
    setWindowTitle(tr("setting"));
    layout->addWidget(testLabel);

    QHBoxLayout *hbox = new QHBoxLayout();
    QPushButton *applyButton = new QPushButton(tr("Apply"), this);
    QPushButton *okButton = new QPushButton("OK", this);

    hbox->addWidget(okButton, 1, Qt::AlignRight);
    hbox->addWidget(applyButton, 0);

    layout->addStretch(1);
    layout->addLayout(hbox);

    connect(applyButton, &QPushButton::clicked, this, &Setting::readJson);
    setLayout(layout);
}

QString Setting::readJson()
{
    // read config from json file
    QFile sourceFile;
    sourceFile.setFileName(":/source/settings.json");
    if (!sourceFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "warning", "Could not open settings.json", QMessageBox::Save, QMessageBox::Cancel);
        return 0;
    }
    QString fileContent = sourceFile.readAll();
    sourceFile.close();

    QJsonDocument d = QJsonDocument::fromJson(fileContent.toUtf8());
    QJsonObject sett2 = d.object();
    QJsonValue value = sett2.value(QString("appName"));

    QJsonObject item = value.toObject();
    QJsonValue subObj = item["description"];
    QString text = subObj.toString();

    return text;
}
