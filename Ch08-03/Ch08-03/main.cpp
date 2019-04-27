//
//  main.cpp
//  Ch08-03
//
//  Created by Stefan Diaconu on 27/04/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include "../../std_lib_facilities.h"

void print(string a, vector<int> b)
{
    for (int i=0; i<b.size(); i++) {
        cout << a << ": " << b[i] << endl;
    }
}

vector<int> fibonacci(int x, int y, vector<int> v, int n)
{
    int nextTerm = 0;
    for (int i=1; i<=n; i++) {
        if (i == 1) {
            v.push_back(x);
            continue;
        }
        if (i == 2) {
            v.push_back(y);
            continue;
        }
        nextTerm = x + y;
        x = y;
        y = nextTerm;
        
        v.push_back(nextTerm);
    }
    return v;
}

int main() {
    // insert code here...
    vector<int> emptyVector;
    vector<int> v = fibonacci(1, 2, emptyVector, 10);
    
    print("Label", v);
}
