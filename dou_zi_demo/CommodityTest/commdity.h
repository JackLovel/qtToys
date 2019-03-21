#ifndef COMMDITY_H
#define COMMDITY_H

#include <string>

using std::string;

class Commdity
{
public:
    Commdity(const string &serialNum,
             const string &name,
             double consting,
             double price);
    string serialNum() const;
    string name() const;
    double consting() const;
    double price() const;  // get price
    void setPrice(double price);
    double profit() const;
    void test(bool b);

private:
    string m_serialNum;
    string m_name;
    double m_consting;
    double m_price;

};

#endif // COMMDITY_H
