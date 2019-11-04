//
//  main.cpp
//  Ch23Drill
//
//  Created by Stefan Diaconu on 01/11/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include <regex>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ifstream in("drill23.txt");
    if(!in) cerr << "no file\n";
    
    regex pat{R"(\w{2}\s*\d{5}(-\d{4})?)"};
    int lineno = 0;
    for (string line; getline(in,line); ){
        ++lineno;
        smatch matches;
        if (regex_search(line, matches, pat))
            cout << lineno << ": " << matches[0] << endl;
    }
    
    return 0;
}
