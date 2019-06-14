//
//  Rational.cpp
//  Ch09-13
//
//  Created by Stefan Diaconu on 12/06/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "Rational.h"

Rational::Rational(int nn, int dd)
    :n(nn), d(dd)
{
}

Rational::~Rational()
{
}

void Rational::operator=(Rational& a)
{
    n = a.n;
    d = a.d;
}

double to_double(Rational& a)
{
    return double(a.numerator()) / double(a.denominator());
}

Rational operator+(Rational& a, Rational& b)
{
    if (a.denominator() == b.denominator()) {
        return Rational((a.numerator() + b.numerator()), a.denominator());
    }
    else {
        return Rational((a.numerator() * b.denominator()) + (b.numerator() * a.denominator()), (a.denominator() * b.denominator()));
    }
}

Rational operator-(Rational& a, Rational& b)
{
    if (a.denominator() == b.denominator()) {
        return Rational((a.numerator() - b.numerator()), a.denominator());
    }
    else {
        return Rational((a.numerator() * b.denominator()) - (b.numerator() * a.denominator()), (a.denominator() * b.denominator()));
    }
}

Rational operator*(Rational& a, Rational& b)
{
    return Rational((a.numerator() * b.numerator()), (a.denominator() * b.denominator()));
}

Rational operator/(Rational& a, Rational& b)
{
    return Rational((a.numerator() * b.denominator()), (a.denominator() * b.numerator()));
}

bool operator==(Rational& a, Rational& b)
{
    return a.numerator() == b.numerator() && a.denominator() == b.denominator();
}

ostream& operator<<(ostream& out, const Rational& a)
{
    return out << a.numerator() << '/' << a.denominator() ;
}
