//
//  main.cpp
//  Ch08-11
//
//  Created by Stefan Diaconu on 29/04/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include "../../std_lib_facilities.h"

void functionF(vector<int> v)
{
    int small = v[0];
    int max = v[0];
    double mean;
    double median;
    double sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] < small) {
            small = v[i];
        }
        if (v[i] > max) {
            max = v[i];
        }
        sum += v[i];
    }
    mean = sum / v.size();
    if (v.size() % 2 == 0) {
        cout << v[(((int)v.size() / 2) - 1)] << endl;
        cout << v[(int)v.size() / 2] << endl;
        median = (double)(v[(((int)v.size() / 2) - 1)] + v[(int)v.size() / 2]) / 2;
    }
    else {
        median = v[((int)v.size() - 1) / 2];
    }
    
    cout << "Small: " << small << ", max: " << max << ", mean: " << mean << ", median: " << median << ", sum: " << sum << endl;
}

int main() {
    // insert code here...
    vector<int> v = {3, 4, 8, 5, 7};
    functionF(v);
}
