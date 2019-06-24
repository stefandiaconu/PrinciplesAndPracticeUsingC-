//
//  main.cpp
//  Ch11-03
//
//  Created by Stefan Diaconu on 24/06/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "../../std_lib_facilities.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<char> vowels = {'a','e','i','o','u'};
    string line = "The quick brown fox jumps over the lazy dog";
    string new_line;
    for (char ch : line) {
        if (ch!='a' && ch!='e' && ch!='i' && ch!='o' && ch!='u' && ch!='A' && ch!='E' && ch!='I' && ch!='O' && ch!='U')
            new_line += ch;
    }
    
    cout << new_line << endl;
    
    return 0;
}
