//
//  main.cpp
//  Ch17DrillA
//
//  Created by Stefan Diaconu on 15/08/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void print_array10(ostream& os, int* a)
{
    int size = sizeof(a) / sizeof(a[0]);
    for (int i=0; i<size; ++i) {
        os << a[i] << '\n';
    }
}

void print_array(ostream& os, int* a, int n)
{
    for (int i=0; i<n; ++i) {
        os << a[i] << '\n';
    }
}

void print_vector(ostream& os, const vector<int>& v)
{
    for (int i=0; i<v.size(); ++i) {
        os << v[i] << '\n';
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int* a = new int[10];
//    int size = sizeof(a) / sizeof(a[0]);
//    std::cout << size << std::endl;
//    for (int i=0; i<size; ++i) {
//        std::cout << a[i] << std::endl;
//    }
//    print_array10(cout, a);
//    cout << endl;
//    delete[] a;
//
//    int* b = new int[10]{101,102,103,104,105,106,107,108,109,110};
//    cout << b[9] << endl;
//    cout << endl;
//
//    int* c = new int[11]{101,102,103,104,105,106,107,108,109,110,111};
//    cout << c[10] << endl;
//    cout << endl;
//
//    print_array(cout, b, 10);
//    delete [] b;
//    cout << endl;
//    print_array(cout, c, 11);
//    delete [] c;
//    cout << endl;
//
//    int* d = new int[20]{101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120};
//    cout << d[19] << endl;
//    print_array(cout, d, 20);
//    delete [] d;
//    cout << endl;
    
    // 5
    vector<int>* v1 = new vector<int>{101,102,103,104,105,106,107,108,109,110};
    print_vector(cout, *v1);
    cout << endl;
    // 6
    vector<int>* v2 = new vector<int>{101,102,103,104,105,106,107,108,109,110,111};
    print_vector(cout, *v2);
    cout << endl;
    // 8
    vector<int>* v3 = new vector<int>{101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120};
    print_vector(cout, *v3);
    cout << endl;
    
    return 0;
}
