//
//  main.cpp
//  Ch10-01
//
//  Created by Stefan Diaconu on 17/06/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "../../std_lib_facilities.h"
#include <unistd.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    char * dir = getcwd(NULL, 0); // Platform-dependent, see reference link below
    printf("Current dir: %s", dir);
    cout << endl;
    
    cout << "Plese enter the input file name: " << endl;
    string iname;
    cin >> iname;
    ifstream ist {iname};
    if (!ist) error("Can't open input file ",iname);
    
    vector<int> numbers;
    int sum = 0;
    int n;
    while(ist>>n) {
        numbers.push_back(n);
    }
    
    for (int i=0; i<numbers.size(); ++i) {
        sum += numbers[i];
    }
    cout << sum << endl;
    
    return 0;
}
