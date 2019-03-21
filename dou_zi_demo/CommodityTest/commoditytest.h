#ifndef COMMODITYTEST_H
#define COMMODITYTEST_H

#include <QtTest/QtTest>

class CommodityTest : public QObject
{
public:
    CommodityTest();
private slots:
    void case1_serialNum();
    void case2_name();
    void case3_consting();
    void case4_price();
    void case5_price();
};

#endif // COMMODITYTEST_H
