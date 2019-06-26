#ifndef TABLEEDITOR_H
#define TABLEEDITOR_H

#include <QWidget>
#include <QDialog>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QtSql/qsqltablemodel.h>

class TableEditor : public QWidget
{
    Q_OBJECT
public:
    TableEditor(const QString &tableName, QWidget *parent = nullptr);

signals:

public slots:

private slots:
    void submit();

private:
    QPushButton *submitButton;
    QPushButton *revertButton;
    QPushButton *quitButton;
    QDialogButtonBox *buttonBox;
    QSqlTableModel *model;
};

#endif // TABLEEDITOR_H








