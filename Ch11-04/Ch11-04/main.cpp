//
//  main.cpp
//  Ch11-04
//
//  Created by Stefan Diaconu on 25/06/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "../../std_lib_facilities.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << "Please enter a number: " << endl;
    vector<string> nums;
    int i = 0;
    while (i<3) {
        string number;
        cin >> number;
        nums.push_back(number);
        ++i;
    }
    
    for (string s: nums) {
        if (s.at(0) == '0') {
            if (s.at(1) == 'x' || s.at(1) == 'X')
                cout << setw(4) << s << "\t" << setw(11) << "hexadecimal" << setw(12) << "\tconverts to\t" << stoi(s,nullptr,16) << "\tdecimal\n";
            else
                cout << setw(4) << s << "\t" << setw(11) << "octal" << setw(12) << "\tconverts to\t" << stoi(s,nullptr,8) << "\tdecimal\n";
        }
        else {
            cout << setw(4) << s << "\t" << setw(11) << "decimal" << setw(12) << "\tconverts to\t" << stoi(s,nullptr,10) << "\tdecimal\n";
        }
    }
    
    return 0;
}
