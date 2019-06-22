//
//  main.cpp
//  Ch10-06
//
//  Created by Stefan Diaconu on 22/06/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "../../std_lib_facilities.h"

class Roman_int
{
private:
    char ch;
public:
    Roman_int(char cc) : ch(cc) {};
    ~Roman_int(){};
    
    char c_value() const { return ch; };
    
    int as_int(char ch)
    {
        int n = 0;
        switch (ch) {
            case 'I': n = 1; break;
            case 'V': n = 5; break;
            case 'X': n = 10; break;
            case 'L': n = 50; break;
            case 'C': n = 100; break;
            case 'D': n = 500; break;
            case 'M': n = 1000; break;
            default: cout << "Not a valid roman numeral!" << endl; break;
        }
        return n;
    };
};

istream& operator>>(istream& is, Roman_int& r)
{
    return is;
}

ostream& operator<<(ostream& os, Roman_int& r)
{
    return os << r.c_value();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << "Enter a roman numeral:" << endl;
    char ch;
    cin >> ch;
    Roman_int r{ch};
    cout << "Roman " << r << " equals " << r.as_int(r.c_value()) << endl;
    
    return 0;
}
