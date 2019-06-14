//
//  Rational.h
//  Ch09-13
//
//  Created by Stefan Diaconu on 12/06/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#ifndef Rational_h
#define Rational_h

#include <iostream>
using namespace std;

class Rational {
  
public:
    Rational(int n, int d);
    ~Rational();
    
    int numerator() const { return n; };
    int denominator() const { return d; };
    
    void operator=(Rational& a);
    
    
private:
    int n;
    int d;
    
};

Rational operator+(Rational& a, Rational& b);
Rational operator-(Rational& a, Rational& b);
Rational operator*(Rational& a, Rational& b);
Rational operator/(Rational& a, Rational& b);

bool operator==(Rational& a, Rational& b);
double to_double(Rational& a);

ostream& operator<<(ostream& out, const Rational& a);

#endif /* Rational_h */
