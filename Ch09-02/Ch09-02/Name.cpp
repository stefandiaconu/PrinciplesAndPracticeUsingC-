//
//  Name.cpp
//  Ch09-02
//
//  Created by Stefan Diaconu on 04/05/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "Name.h"

Name::Name()
{
}

Name::~Name()
{
}

void Name::read_names()
{
    int count = 0;
    string n;
    
    while (cin) {
        cout << "Please enter a name: " << endl;
        cin >> n;
        if (n == "x")
            break;
        names.push_back(n);
        count++;
    }
}

void Name::read_ages()
{
    int count = 0;
    double a;
    
    while (count < names.size()) {
        cout << "Please enter an age: " << endl;
        cin >> a;
        ages.push_back(a);
        count++;
    }
}

void Name::print()
{
    for (int i = 0; i < names.size(); ++i) {
        cout << "Name: " << names[i] << ", age: " << ages[i] << endl;
    }
}

void Name::sort_names()
{
    vector<string> name2 = names;
    vector<double> age2;
    sort(names.begin(), names.end());
    for (int i = 0; i < names.size(); i++) {
        for (int j = 0; j < name2.size(); j++) {
            if (names[i] == name2[j]){
                age2.push_back(ages[j]);
            }
        }
    }
    ages = age2;
}

ostream& operator<<(ostream& os, const Name& n)
{
    for (int i = 0; i < n.names.size(); ++i) {
        for (int j = 0; j < n.names[i].size(); ++j) {
            os.put(n.names[i].at(j));
        }
        os.put(',');
        string x = to_string((int)n.ages[i]);   // cast the age (double) to 'int' and convert to_string
        for (int k = 0; k < x.size(); ++k) {
            os.put(x[k]);
        }
        os.put('\n');
    }
    return os;
}

bool operator==(const Name& a, const Name& b)
{
    return a.names==b.names && a.ages==b.ages;
}

bool operator!=(const Name& a, const Name& b)
{
    return !(a==b);
}
