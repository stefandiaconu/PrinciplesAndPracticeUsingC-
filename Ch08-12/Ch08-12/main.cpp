//
//  main.cpp
//  Ch08-12
//
//  Created by Stefan Diaconu on 29/04/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include "../../std_lib_facilities.h"

void print_until_s(vector<string> v, string quit)
{
    for (string s : v) {
        if (s == quit) return;
        cout << s << endl;
    }
}

void print_until_ss(vector<string> v, string quit)
{
    int count = 0;
    for (string s : v) {
        if (s == quit) {
            count++;
            if (count == 2) return;
        }
        cout << s << endl;
    }
}

int main() {
    // insert code here...
    vector<string> v = {"alpha","beta","gamma","delta","kappa","sigma","theta","delta","omega"};
    string s = "delta";
    
    print_until_s(v, s);
    
    cout << endl;
    
    print_until_ss(v, s);
    
    return 0;
}
