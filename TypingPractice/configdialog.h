#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include <QStackedWidget>

class ConfigDialog : public QDialog
{
public:
    ConfigDialog(QWidget *parent = 0);

public slots:
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);

private:
    void createIcons();

    QListWidget *contentsWidget;
    QStackedWidget *pagesWidget;
};

#endif // CONFIGDIALOG_H
