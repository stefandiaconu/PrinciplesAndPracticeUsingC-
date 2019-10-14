//
//  main.cpp
//  Ch20Drill
//
//  Created by Stefan Diaconu on 09/10/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include <array>
#include <vector>
#include <list>
using namespace std;

template<typename Iter1, typename Iter2>
    // requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    while (f1 != e1) {
        *f2 = *f1;
        ++f1;
        ++f2;
    }
    return f2;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello World!" << endl;
    
    array<int, 10> arr = {0,1,2,3,4,5,6,7,8,9};
    vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    list<int> l = {0,1,2,3,4,5,6,7,8,9};
    array<int, 10> arr2 = arr;
    vector<int> v2 = v;
    list<int> l2 = l;
    
    for (array<int,10>::iterator p = arr.begin(); p != arr.end(); ++p) {
        *p += 2;
    }

    for (vector<int>::iterator p = v.begin(); p != v.end(); ++p) {
        *p += 3;
    }

    for (list<int>::iterator p = l.begin(); p != l.end(); ++p) {
        *p += 5;
    }

    for (int i=0; i<10; ++i) {
        cout << arr[i] << ", " << arr2[i] << endl;
    }
    cout << endl;
    for (int i=0; i<10; ++i) {
        cout << v[i] << ", " << v2[i] << endl;
    }
    cout << endl;
    for (auto a : l)
        cout << "l: " << a << endl;
    cout << endl;
    for (auto a : l2)
        cout << "l2: " << a << endl;
    cout << endl;
    
    copy(begin(arr), end(arr), begin(v));
    array<int,10>::iterator it = my_copy(l.begin(), l.end(), arr.begin());
    
    for (auto x : v)
        cout << x << endl;
    cout << endl;
    for (auto x : arr)
        cout << x << endl;
    cout << endl;
    
    vector<int>::iterator p = find(v.begin(), v.end(), 27);
    if (p != v.end())
        cout << "True" << endl;
    else cout << "False" << endl;
    cout << endl;
    int index = distance(v.begin(), p);
    cout << index << endl;
    cout << endl;
        
    cout << p.base() << endl;
    
    return 0;
}
