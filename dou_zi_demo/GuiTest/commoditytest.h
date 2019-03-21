#ifndef COMMODITYTEST_H
#define COMMODITYTEST_H

#include <QtWidgets>
#include <QtTest/QTest>

class CommodityTest : public QObject
{
   Q_OBJECT

public:
    CommodityTest();

private slots:
    void case1_gui_consting();
    void case2_gui_price();
    void case3_gui_profit();
};

#endif // COMMODITYTEST_H
