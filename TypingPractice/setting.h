#ifndef SETTING_H
#define SETTING_H

#include <QDialog>
#include <QLabel>

class Setting : public QDialog
{
    Q_OBJECT
public:
    Setting(QWidget *parent = 0);

private:
    QString readJson();
    QLabel *testLabel;
};

#endif // SETTING_H
