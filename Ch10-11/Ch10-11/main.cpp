//
//  main.cpp
//  Ch10-11
//
//  Created by Stefan Diaconu on 23/06/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "../../std_lib_facilities.h"

bool isNumber(string line)
{
    return (atoi(line.c_str()));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int sum = 0;
    
    ifstream ist;
    ist.open("mydata.txt",ios_base::out);
    
    vector<string> ns;
    while(true){
        string s;
        if (!(ist>>s)) break;
        ns.push_back(s);
    }
    ist.close();
    
    for (string s : ns) {
        if (isNumber(s)) {
            int n = stoi(s);
            sum += n;
        }
    }

    cout << sum << endl;
    
    return 0;
}
