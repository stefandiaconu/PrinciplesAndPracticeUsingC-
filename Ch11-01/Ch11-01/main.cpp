//
//  main.cpp
//  Ch11-01
//
//  Created by Stefan Diaconu on 23/06/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "../../std_lib_facilities.h"

void to_lower(string& s)
{
    for (char& x : s) x = tolower(x);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ifstream is;
    is.open("mydata.txt",ios_base::out);
    vector<string> vs;
    while (true) {
        string s;
        if (!(is>>s)) break;
        vs.push_back(s);
    }
    is.close();
    
    for (string s : vs) {
        cout << s << endl;
    }
    
    vector<string> new_vs;
    for (string s : vs) {
        to_lower(s);
        new_vs.push_back(s);
    }
    
    cout << endl;
    
    for (string s : new_vs) {
        cout << s << endl;
    }
    
    ofstream os;
    os.open("mydata2.txt",ios_base::out);
    for (int i=0; i<new_vs.size(); ++i) {
        os << new_vs[i] << '\n';
    }
    os.close();
    
    return 0;
}
