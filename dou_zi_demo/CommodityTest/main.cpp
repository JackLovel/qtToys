#include <QCoreApplication>
#include "commdity.h"
#include <QDebug>

int cntPass = 0;
int cntFail = 0;
void test(bool b)
{
    if (b)
        ++cntPass;
    else
        ++cntFail;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Commdity c("beer_1", "beer", 4, 5);

    test(c.serialNum() == "beer_1");
    test(c.name() == "beer");
    test(c.consting() == 4);
    test(c.price() == 5);
    test(c.profit() == 1);

    qDebug() << "cntPass:" << cntPass << "\ncntFail:" << cntFail;
    return a.exec();
}
