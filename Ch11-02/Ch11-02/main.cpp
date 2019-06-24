//
//  main.cpp
//  Ch11-02
//
//  Created by Stefan Diaconu on 24/06/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "../../std_lib_facilities.h"

void get_word(ifstream& ifs, string& word)
{
    int line_number = 0;
    string line;
    while (getline(ifs, line)) {
        ++line_number;
        if (line.find(word) != string::npos)
        {
            cout << line << " at position " << line_number << " contains the word " << word << endl;
        }
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ifstream ifs;
    ifs.open("mydata.txt",ios_base::out);
    string word = "dog";
    get_word(ifs, word);
    
    return 0;
}
