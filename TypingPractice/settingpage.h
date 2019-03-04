#ifndef SETTINGPAGE_H
#define SETTINGPAGE_H

#include <QDialog>
#include <QWidget>


class BasicConfigPage : public QWidget
{
public:
    BasicConfigPage(QWidget *parent = 0);
};


class ScorePage : public QWidget
{
public:
    ScorePage(QWidget *parent = 0);
};


class ShortcutPage : public QWidget
{
public:
    ShortcutPage(QWidget *parent = 0);
};


class TypeingConfigPage : public QWidget
{
public:
    TypeingConfigPage(QWidget *parent = 0);
};


class AdvancedConfigPage : public QWidget
{
public:
    AdvancedConfigPage(QWidget *parent = 0);
};
#endif // SETTINGPAGE_H
