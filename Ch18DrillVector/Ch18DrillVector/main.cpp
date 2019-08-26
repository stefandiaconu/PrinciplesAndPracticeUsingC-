//
//  main.cpp
//  Ch18DrillVector
//
//  Created by Stefan Diaconu on 26/08/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> gv =  {1,2,4,8,16,32,63,128,256,512};

void f(vector<int> v) {
    vector<int> lv;
    for (int i=0; i<v.size(); ++i) {
        lv.push_back(v[i]);
        cout << lv[i] << ",";
    }
    
    cout << endl;
    
    vector<int> lv2 (v.begin(), v.end());
    for (int x : lv2)
        cout << x << ",";
    
    cout << endl;
}

int fact(int n) {
    if (n==0 || n==1)
        return 1;
    else
        return n*fact(n-1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    f(gv);
    cout << endl;
    
    vector<int> vv;
    for (int i=0; i<10; ++i) {
        vv.push_back(fact(i));
    }
    
    for (int x : vv)
        cout << x << ",";
    
    cout << endl;
    
    return 0;
}
