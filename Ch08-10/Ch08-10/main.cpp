//
//  main.cpp
//  Ch08-10
//
//  Created by Stefan Diaconu on 28/04/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include "../../std_lib_facilities.h"

int maxv(vector<int> v)
{
    int max = 0;
    
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > max)
            max = v[i];
    }
    
    return max;
}

int main() {
    // insert code here...
    vector<int> v = {44, 12, 5, 4};
    int max;
    max = maxv(v);
    cout << "Max: " << max << endl;
    
}
