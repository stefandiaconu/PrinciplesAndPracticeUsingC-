//
//  Name.h
//  Ch09-02
//
//  Created by Stefan Diaconu on 04/05/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#ifndef Name_h
#define Name_h
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Name {
    
public:
    vector<string> names;
    vector<double> ages;
    Name();
    ~Name();
    
    void read_names();
    void read_ages();
    void print();
    void sort_names();
};

ostream& operator<<(ostream& os, const Name& n);
bool operator==(const Name& a, const Name& b);
bool operator!=(const Name& a, const Name& b);

#endif /* Name_h */
