//
//  Money.h
//  Ch09-14
//
//  Created by Stefan Diaconu on 23/09/2020.
//

#ifndef Money_h
#define Money_h

#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

enum class Currency { USD, DKK };

class Money {
    
public:
    Money(const long int&, const Currency&);
    Money(const long int&);
    Money();
    ~Money();
    
    long int get_cents() const { return cents; };
    
    double get_dollars() const { return (double)cents / 100 ; }
    
    Currency get_currency() const { return currency; };
    
private:
    long int cents;
    Currency currency;
};

double exchange_rate(const Currency&, const Money&);

bool operator==(Money&, Money&);
bool operator!=(Money&, Money&);

ostream& operator<<(ostream&, const Money&);
istream& operator>>(istream&, const Money&);

Money operator+(const Money&, const Money&);
Money operator-(const Money&, const Money&);
Money operator*(const Money&, const int&);
Money operator/(const Money&, const int&);

#endif /* Money_h */
