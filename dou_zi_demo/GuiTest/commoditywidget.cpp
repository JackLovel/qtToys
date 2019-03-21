#include "commoditywidget.h"
#include "ui_commoditywidget.h"
#include <commdity.h>

CommodityWidget::CommodityWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CommodityWidget)
{
    ui->setupUi(this);

}

CommodityWidget::~CommodityWidget()
{
    delete ui;
}

double CommodityWidget::consting() const
{
    return ui->lineEdit->text().toDouble();
}

double CommodityWidget::price() const
{
    return ui->lineEdit_2->text().toDouble();
}

double CommodityWidget::profit() const
{
    return ui->lineEdit_3->text().toDouble();
}

void CommodityWidget::showProfit()
{
    double c = consting();
    double p = price();
    Commdity commodity("beer_1", "beer", c, p);
    ui->lineEdit_3->setText(QString::number(commodity.profit()));
}

void CommodityWidget::on_lineEdit_textChanged(const QString &arg1)
{
    showProfit();
}

void CommodityWidget::on_lineEdit_2_textChanged(const QString &arg1)
{
    showProfit();
}
