//
//  main.cpp
//  Ch08-05
//
//  Created by Stefan Diaconu on 27/04/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include "../../std_lib_facilities.h"

vector<int> reverseVector(vector<int> v1, vector<int> v2)
{
    int x = (int)v1.size()-1;
    for (int i=x; i>=0; i--) {
        v2.push_back(v1[i]);
    }
    return v2;
}

vector<int> swapVector(vector<int> v)
{
    for ( int i=0; i<v.size() / 2; i++) {
        swap(v[i], v[(int)v.size()-1-i]);
    }
    return v;
}

int main() {
    // insert code here...
    vector<int> v1 = {1, 3, 5, 7, 9};
    vector<int> v2;
    v2 = reverseVector(v1, v2);
    for (int i=0; i<v2.size(); i++) {
        cout << v2[i] << "," << endl;
    }
    
    cout << endl;
    
    v2 = swapVector(v1);
    for (int i=0; i<v2.size(); i++) {
        cout << v2[i] << "," << endl;
    }
}
