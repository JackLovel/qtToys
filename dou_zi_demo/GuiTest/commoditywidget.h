#ifndef COMMODITYWIDGET_H
#define COMMODITYWIDGET_H

#include <QWidget>
#include <QMainWindow>
namespace Ui {
class CommodityWidget;
}

class CommodityWidget : public QMainWindow
{
    Q_OBJECT

public:
    friend class CommodityTest;
    explicit CommodityWidget(QWidget *parent = 0);
    ~CommodityWidget();
    double consting() const;
    double price() const;
    double profit() const;

public slots:
    void showProfit();

    void on_lineEdit_textChanged(const QString &arg1);
    void on_lineEdit_2_textChanged(const QString &arg1);


private:
    Ui::CommodityWidget *ui;
};

#endif // COMMODITYWIDGET_H
