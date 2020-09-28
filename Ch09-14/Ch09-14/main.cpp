//
//  main.cpp
//  Ch09-14
//
//  Created by Stefan Diaconu on 23/09/2020.
//

#include <iostream>
#include "Money.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Money m1{947, Currency::DKK};
    Money m2{123, Currency::USD};
    
    Money m3 = m1 + m2;
    Money m4 = m1 - m2;
    
    cout << "M1: " << m1 << endl;
    cout << "M2: " << m2 << endl;
    cout << "M3: " << m3 << endl;
    cout << "M4: " << m4 << endl;
    
    return 0;
}
