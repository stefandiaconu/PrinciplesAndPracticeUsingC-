//
//  main.cpp
//  Ch08-09
//
//  Created by Stefan Diaconu on 29/04/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include "../../std_lib_facilities.h"

double compute(vector<double> price, vector<double> weight)
{
    double sum = 0;
    
    for (int i = 0; i < price.size(); ++i) {
        sum += price[i] * weight[i];
    }
    
    return sum;
}

int main() {
    // insert code here...
    vector<double> price = {1, 2, 3};
    vector<double> weight = {1, 2, 3};
    double sum = 0.0;
    if (price.size() == weight.size()) {
        sum = compute(price, weight);
    }
    else {
        cout << "The two vectors aree not equal" << endl;
    }
    
    cout << "Sum: " << sum << endl;
    
    return 0;
}
