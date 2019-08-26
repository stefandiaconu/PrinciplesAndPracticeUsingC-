//
//  main.cpp
//  Ch18DrillArray
//
//  Created by Stefan Diaconu on 26/08/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
using namespace std;

// 1
int ga[10] = {1,2,4,8,16,32,64,128,256,512};

// 2
void f(const int array[], int n) {
    int la[10];
    for (int i=0; i<n; ++i) {
        la[i] = array[i];
        cout << la[i] << ",";
    }
    cout << endl;
    int* p = new int[n];
    for (int i=0; i<n; ++i) {
        p[i] = array[i];
        cout << p[i] << ",";
    }
    delete[] p;
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
    
    f(ga, 6);
    
    cout << endl;
    
    int aa[10];
    for (int i=0; i<10; ++i) {
        aa[i] = fact(i);
    }
    f(aa,10);
    
    return 0;
}
