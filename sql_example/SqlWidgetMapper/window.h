#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QComboBox>
#include <QDataWidgetMapper>
#include <QItemSelectionModel>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSqlRelationalTableModel>
#include <QStandardItemModel>
#include <QStringListModel>
#include <QTextEdit>

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);

private slots:
    void updateButtons(int row);

private:
    void setupModel();

    QLabel *nameLabel;
    QLabel *addressLabel;
    QLabel *typeLabel;
    QLineEdit *nameEdit;
    QTextEdit *addressEdit;
    QComboBox *typeComboBox;
    QPushButton *nextButton;
    QPushButton *previousButton;

    QSqlRelationalTableModel *model;
    QItemSelectionModel *selectionModel;
    QDataWidgetMapper *mapper;
    int typeIndex;
};

#endif // WINDOW_H
