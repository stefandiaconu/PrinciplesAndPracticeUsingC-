//
//  main.cpp
//  Ch11-05
//
//  Created by Stefan Diaconu on 25/06/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "../../std_lib_facilities.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << "Please enter a string: " << endl;
    string s;
    while (cin>>s) {
        for (char ch: s) {
            if (isspace(ch))
                cout << "Character " << ch << " is a space character!" << endl;
            else if (isxdigit(ch))
                cout << "Character " << ch << " is a hex digit character!" << endl;
            else if (isalpha(ch))
                cout << "Character " << ch << " is an alpha character!" << endl;
            else if (isdigit(ch))
                cout << "Character " << ch << " is a digit character!" << endl;
            else if (isupper(ch))
                cout << "Character " << ch << " is an upper character!" << endl;
            else if (islower(ch))
                cout << "Character " << ch << " is a lower character!" << endl;
            else if (isalnum(ch))
                cout << "Character " << ch << " is a alnum character!" << endl;
            else if (iscntrl(ch))
                cout << "Character " << ch << " is an cntrl character!" << endl;
            else if (ispunct(ch))
                cout << "Character " << ch << " is a punct character!" << endl;
            else if (isprint(ch))
                cout << "Character " << ch << " is a print character!" << endl;
            else if (isgraph(ch))
                cout << "Character " << ch << " is a graph character!" << endl;
            else
                cout << "Character not identified! " << ch << endl;
        }
    }
    
    return 0;
}
