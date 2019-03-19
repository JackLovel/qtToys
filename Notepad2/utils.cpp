#include "utils.h"

#include <QFile>
#include <QWidget>
#include <QKeySequence>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonObject>
#include <QString>
#include <QMessageBox>

// @https://blog.csdn.net/qq_31073871/article/details/79943093
void Utils::loadStyleSheet(const QString &styleSheetFile, QWidget *widget)
{
    QFile file(styleSheetFile);
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QString styleSheet = widget->styleSheet();
        styleSheet += QLatin1String(file.readAll());
        widget->setStyleSheet(styleSheet);
        file.close();
    }
}


QKeySequence Utils::readJson(QWidget *widget, const QString &fileAlias, const QString &key)
{
    QString jsonPath("");
    if (fileAlias == "menu")
    {
        jsonPath = ":/settings/keys.json";
    }
    else if (fileAlias == "other")
    {
        jsonPath = "";
    }

    QFile file;

    file.setFileName(jsonPath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(widget, "config file not found", "key config is maybe deleted or not exist!");
        return QString();
    }

    QString val = file.readAll();
    file.close();

    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();
    QJsonValue value = sett2.value(QString(key));
    QJsonObject item = value.toObject();
    QJsonValue subobj = item["default"];
    QString kk = subobj.toString();

    // array
    // QJsonArray test = item["default"].toArray();
    // qDebug() << test[1].toString();

    QKeySequence::fromString(kk);
    return kk;
}
