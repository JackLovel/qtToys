#include "commoditytest.h"
#include "commdity.h"
#include "commoditywidget.h"
#include "ui_commoditywidget.h"

void CommodityTest::case1_gui_consting()
{
    CommodityWidget w;

    QTest::keyClicks(w.ui->lineEdit_2, "5.0");
    QCOMPARE(w.consting(), 5.0);
}

void CommodityTest::case2_gui_price()
{
    CommodityWidget w;

    QTest::keyClicks(w.ui->lineEdit, "5.0");
    QCOMPARE(w.consting(), 5.0);
}

void CommodityTest::case3_gui_profit()
{
    CommodityWidget w;

    QTest::keyClicks(w.ui->lineEdit_2, "5.0");
    QTest::keyClicks(w.ui->lineEdit, "7.2");

    QCOMPARE(w.profit(), 2.2);
}
