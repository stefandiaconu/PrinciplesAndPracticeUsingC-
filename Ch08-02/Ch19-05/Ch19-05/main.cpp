//
//  main.cpp
//  Ch19-05
//
//  Created by Stefan Diaconu on 17/09/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
using namespace std;

// Ch19-05
class Int
{
    int val;
public:
    Int() : val{0} {}
    Int(const Int& arg) : val{arg.val} {}
    Int(int v) : val{v} {}
    Int& operator=(const Int& v) { val = v.val; return *this; }
    
    int get() const { return val; };
};

Int operator+(const Int& v1, const Int& v2)
{
    return Int(v1.get() + v2.get());
}

Int operator-(const Int& v1, const Int& v2)
{
    return Int(v1.get() - v2.get());
}

Int operator*(const Int& v1, const Int& v2)
{
    return Int(v1.get() * v2.get());
}

Int operator/(const Int& v1, const Int& v2)
{
    return Int(v1.get() / v2.get());
}

ostream& operator<<(ostream& os, const Int& i)
{
    return os << i.get();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // Ch19-05
    Int i1;
    Int i2 = 2;
    Int i3(i2);
    Int i4;
    i4 = i2;
    Int i5 = 6;
    cout << "i1 (default constructed): " << i1 << "\n";
    cout << "i2 (constructed with argument): " << i2 << "\n";
    cout << "i3 (copy constructed from i2): " << i3 << "\n";
    cout << "i4 (copy assigned  from i2): " << i4 << "\n";
    cout << "i5 (constructed with argument): " << i5 << "\n";
    cout << "i2 + i5 = " << i2+i5 << "\n";
    cout << "i5 - i2 = " << i5-i2 << "\n";
    cout << "i2 * i5 = " << i2*i5 << "\n";
    cout << "i5 / i2 = " << i5/i2 << "\n";
    
    return 0;
}
