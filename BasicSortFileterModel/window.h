#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemDelegate>
#include <QComboBox>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QSortFilterProxyModel>
#include <QTreeView>
#include <QCheckBox>

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();

    void setSourceModel(QAbstractItemModel *model);

    ~Window();

private slots:
    void filterRegExpChanged();
    void filterColumnChanged();
    void sortChanged();

private:
    QSortFilterProxyModel *proxyModel;

    QGroupBox *sourceGroupBox;
    QGroupBox *proxyGroupBox;
    QTreeView *sourceView;
    QTreeView *proxyView;
    QCheckBox *filterCaseSensitivityCheckBox;
    QCheckBox *sortCaseSensitivityCheckBox;
    QLabel *filterPatternLabel;
    QLabel *filterSyntaxLabel;
    QLabel *filterColumnLabel;
    QLineEdit *filterPatternLineEdit;
    QComboBox *filterSyntaxComboBox;
    QComboBox *filterColumnComboBox;

};

#endif // MAINWINDOW_H























