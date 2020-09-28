//
//  Money.cpp
//  Ch09-14
//
//  Created by Stefan Diaconu on 23/09/2020.
//

#include "Money.h"

Money::Money(const long int& c, const Currency& cur)
    : cents{c}, currency{cur}
{
}

Money::Money(const long int& c)
    : cents{c}
{
}

Money::Money()
{
}

Money::~Money()
{
}

double exchange_rate(const Currency& cur, const Money& m)
{
    switch (cur) {
        case Currency::USD:
            return m.get_cents() * 6.40;
            break;
        case Currency::DKK:
            return m.get_cents() * 0.16;
            break;
        default:
            return 0;
            break;
    }
    return 0;
}

bool operator==(Money& a, Money& b)
{
    return a.get_cents() == b.get_cents() && a.get_currency() == b.get_currency();
}

bool operator!=(Money& a, Money& b)
{
    return !(a == b);
}

ostream& operator<<(ostream& os, const Money& money)
{
    string currency_name = "";
    switch (money.get_currency()) {
        case Currency::USD:
            currency_name = "USD";
            break;
        case Currency::DKK:
            currency_name = "DKK";
            break;
        default:
            currency_name = "No valid currency.";
            break;
    }
    os << fixed << setprecision(2) << money.get_dollars() << " " << currency_name;
    return os;
}

istream& operator>>(istream& is, const Money& money)
{
    return is;
}

Money operator+(const Money& a, const Money& b)
{
    if (a.get_currency() == b.get_currency()) {
        return a.get_cents() + b.get_cents();
    }
    else {
        double currency_converted = exchange_rate(b.get_currency(), b);
        return Money{a.get_cents() + currency_converted, a.get_currency()};
    }
}

Money operator-(const Money& a, const Money& b)
{
    if (a.get_currency() == b.get_currency()) {
        return a.get_cents() - b.get_cents();
    }
    else {
        double currency_converted = exchange_rate(b.get_currency(), b);
        return Money{a.get_cents() - currency_converted, a.get_currency()};
    }
}

Money operator*(const Money& a, const int& n)
{
    return a.get_dollars() * n;
}

Money operator/(const Money& a, const int& n)
{
    return a.get_dollars() / n;
}

