//
//  main.cpp
//  Ch09-13
//
//  Created by Stefan Diaconu on 12/06/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "Rational.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Rational r1(3, 8), r2(1, 2), r3(10, 2);
    cout << r1 << " * " << r2 << " = " << r1 * r2 << '\n'
        << r2 << " * " << r3 << " = " << r2 * r3 << '\n';
    
    cout << endl;
    
    cout << r1 << " + " << r2 << " = " << r1 + r2 << '\n'
    << r2 << " + " << r3 << " = " << r2 + r3 << '\n';
    
    cout << endl;
    
    cout << r1 << " - " << r2 << " = " << r1 - r2 << '\n'
    << r2 << " - " << r3 << " = " << r2 - r3 << '\n';
    
    cout << endl;
    
    cout << r1 << " / " << r2 << " = " << r1 / r2 << '\n'
    << r2 << " / " << r3 << " = " << r2 / r3 << '\n';
    
    cout << endl;
    
    Rational b(5, 6);
    
    double a = to_double(b);
    
    cout << a << endl;
    
    Rational c = b;
    
    cout << c << endl;
    
    return 0;
}
