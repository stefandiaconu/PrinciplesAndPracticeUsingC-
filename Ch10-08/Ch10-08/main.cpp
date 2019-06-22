//
//  main.cpp
//  Ch10-08
//
//  Created by Stefan Diaconu on 22/06/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "../../std_lib_facilities.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ifstream file1("mydata1.txt");
    ifstream file2("mydata2.txt");
    ofstream file3("mydata3.txt");
    file3 << file1.rdbuf() << file2.rdbuf();
    
    return 0;
}
