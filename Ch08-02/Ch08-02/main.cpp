//
//  main.cpp
//  Ch08-02
//
//  Created by Stefan Diaconu on 27/04/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include "../../std_lib_facilities.h"

void print(string a, vector<int> b)
{
    for (int i=0; i<b.size(); i++){
        cout << a << ": " << b[i] << endl;
    }
}

int main() {
    // insert code here...
    vector<int> v = {1, 2, 3, 4, 5};
    print("Label", v);
    
    return 0;
}
