#include "commdity.h"
#include <iostream>
#include <iostream>

using std::cout;


Commdity::Commdity(const string &serialNum, const string &name,
             double consting, double price)
{
    m_serialNum = serialNum;
    m_name = name;
    m_consting = consting;
    setPrice(price);
}


string Commdity::serialNum() const
{
    return m_serialNum;
}

string Commdity::name() const
{
    return m_name;
}

double Commdity::consting() const
{
    return m_consting;
}

double Commdity::price() const
{
    return m_price;
}

void Commdity::setPrice(double price)
{
    m_price = price;
}

double Commdity::profit() const
{
    return price() - consting();
}
