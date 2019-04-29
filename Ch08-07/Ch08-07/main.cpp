//
//  main.cpp
//  Ch08-07
//
//  Created by Stefan Diaconu on 28/04/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include "../../std_lib_facilities.h"

int main() {
    // insert code here...
    vector<string> name;
    vector<double> age;
    string n;
    double a;
    int count = 0;
    
    while (count < 5) {
        cout << "Please enter a name: " << endl;
        cin >> n;
        name.push_back(n);
        count++;
    }
    
    count = 0;
    
    while (count < 5) {
        cout << "Please enter an age: " << endl;
        cin >> a;
        age.push_back(a);
        count++;
    }
    
    for (int i = 0; i < name.size(); i++) {
        cout << "Name: " << name[i] << ", age: " << age[i] << endl;
    }
    
    cout << endl;
    
    vector<string> name2 = name;
    sort(name.begin(), name.end());
    for (int i = 0; i < name.size(); i++) {
        for (int j = 0; j < name2.size(); j++) {
            if (name[i] == name2[j]){
                cout << "Name: " << name[i] << ", age: " << age[j] << endl;
            }
        }
    }
    
    return 0;
}
