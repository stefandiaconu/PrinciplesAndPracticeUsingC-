//
//  main.cpp
//  Ch17DrillB
//
//  Created by Stefan Diaconu on 16/08/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int a = 7;
    int* p1 = new int(7);
    cout << a << endl;
    cout << *p1 << endl;
    
    int b[] = {1,2,4,8,16,32,64};
    int* p2 = new int[1,2,4,8,16,32,64];
    cout << b << endl;
    cout << *p2 << endl;
    
    int* p3 = p2;
    p2 = p1;
    p2 = p3;
    cout << *p1 << endl;
    cout << *p2 << endl;
    
    delete p1;
    delete [] p2;
    p1 = NULL;
    //delete [] p3;
    
    cout << endl;
    cout << p1 << endl;
    cout << p2 << endl;
    
//    int c[] = {1,2,4,8,16,32,64,128,256,512};
//    p1 = c;
//    int d[] = {1,2,4,8,16,32,64,128,256,512};
//    p2 = d;
//    p2 = p1;
    
    vector<int> v1 {1,2,4,8,16,32,64,128,256,512};
    vector<int> v2 {1,2,4,8,16,32,64,128,256,512};
    v2 = v1;
    
    return 0;
}
