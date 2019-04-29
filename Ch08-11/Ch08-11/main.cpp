//
//  main.cpp
//  Ch08-11
//
//  Created by Stefan Diaconu on 29/04/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include "../../std_lib_facilities.h"

// create function to return values by reference
void functionByReference(int& small, int& max, double& mean, double& median, vector<int> v)
{
    small = v[0];
    max = v[0];
    mean = 0.0;
    median = 0.0;
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
        median = (double)(v[(((int)v.size() / 2) - 1)] + v[(int)v.size() / 2]) / 2;
    }
    else {
        median = v[((int)v.size() - 1) / 2];
    }
    
    //cout << "Small: " << small << ", max: " << max << ", mean: " << mean << ", median: " << median << ", sum: " << sum << endl;
}

// create struct with values to return
struct x {
    int small;
    int max;
    double mean;
    double median;
};

// create function of type struct to return values to struct
x functionReturnStruct(vector<int> v)
{
    x newX;
    int small = v[0];
    int max = v[0];
    double mean = 0.0;
    double median = 0.0;
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
        median = (double)(v[(((int)v.size() / 2) - 1)] + v[(int)v.size() / 2]) / 2;
    }
    else {
        median = v[((int)v.size() - 1) / 2];
    }
    
    newX.small = small;
    newX.max = max;
    newX.mean = mean;
    newX.median = median;
    
    return newX;
    //cout << "Small: " << small << ", max: " << max << ", mean: " << mean << ", median: " << median << ", sum: " << sum << endl;
}

int main() {
    // insert code here...
    vector<int> v = {4, 10, 4, 7, 2, 4};
    
    // return values by reference
    int small;
    int max;
    double mean;
    double median;
    functionByReference(small, max, mean, median, v);
    cout << "Small: " << small << ", max: " << max << ", mean: " << mean << ", median: " << median << endl;
    
    // retrun values in a struct
    x result;
    result = functionReturnStruct(v);
    cout << "Small: " << result.small << ", max: " << result.max << ", mean: " << result.mean << ", median: " << result.median << endl;
    
    return 0;
}
