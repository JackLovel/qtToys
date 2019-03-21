#include "commoditytest.h"
#include "commdity.h"

void CommodityTest::case1_serialNum()
{
    // test product number
    Commdity c("beer_1", "beer", 4, 5);
    QVERIFY(c.serialNum() == "beer_1");
}

void CommodityTest::case2_name()
{
    // test product name
    Commdity c("beer_1", "beer", 4, 5);
    QVERIFY(c.name() == "beer");
}

void CommodityTest::case3_consting()
{
    // test product price
    Commdity c("beer_1", "beer", 4, 5);
    QVERIFY(c.consting() == 4);
}

void CommodityTest::case4_price()
{
    Commdity c("beer_1", "beer", 4, 5);
    QVERIFY(c.price() == 5);
}

void CommodityTest::case5_profit()
{
    Commdity c("beer_1", "beer", 4, 5);
    QVERIFY(c.profit() == 1);
}
