//
//  main.cpp
//  Ch09-02
//
//  Created by Stefan Diaconu on 04/05/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "Name.h"

int main() {
    // insert code here...
    Name name;
    name.read_names();
    name.read_ages();
    name.print();
    cout << endl;
    name.sort_names();
    name.print();
    cout << endl;
    cout << name << endl;
    
    return 0;
}
