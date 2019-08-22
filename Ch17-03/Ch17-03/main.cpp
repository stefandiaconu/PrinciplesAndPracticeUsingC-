//
//  main.cpp
//  Ch17-03
//
//  Created by Stefan Diaconu on 17/08/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>

// Ch17-03
void to_lower(char* s)
{
    for (int i=0; s[i]; ++i)
    {
        if (s[i] >= 65 && s[i] <= 90)
            s[i] += 32;
        std::cout << s[i];
    }
    std::cout << std::endl;
}

// Ch17-04
char* strdup(const char* s)
{
    if (s==0) return 0;
    //get number of char in s
    int n = 0;
    while (s[n] != 0)
        ++n;
    // allocate memory with room for terminating 0
    char* ss = new char[n+1];
    // copy string
    for (int i=0; s[i]; ++i)
        ss[i] = s[i];
    // zero terminated
    ss[n] = 0;
    
    return ss;
}

// Ch17-05
const char* findx(const char* s, const char* x)
{
    if (x==0) return 0;
    for (int i=0; s[i]; ++i) {
        if (s[i] == x[0]) {
            for (int j=1; x[j]; ++j) {
                if (s[i+j] != x[j]) break;
                if (x[j+1] == 0) return &x[0];
                if (s[i+j+1] == 0) return 0;
            }
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    // Ch17-03
//    char s[] = "Hello, World!";
//    to_lower(s);
//
//    // Ch17-04
//    std::string s2;
//    char* str;
//    while(std::cin>>s2 && s2!="quit")
//    {
//        str = strdup(&s2[0]);
//        std::cout << str << '\n';
//        delete [] str;
//    }
    
//    // Ch17-05
//    char s[] = "The quick brown fox jumps over the lazy dog";
//    char x[] = "fox";
//    const char* result = findx(s, x);
//    std::cout << result << std::endl;
    
//    // Ch17-06
//    int n = 1;
//    while (n>0){
//        double* d = new double[100000];
//        double* d2 = new double[100000];
//        double* d3 = new double[100000];
//        std::cout << d << d2 << d3 << std::endl;
//    }
    
//    // Ch17-07
//    char* array = new char[10];
//    char ch;
//    while (std::cin >> ch && ch!='!') {
//        array = &ch;
//    }
//    std::cout << &array[0] << std::endl;
    
    // Ch17-08
    std::string s;
    char ch;
    while (std::cin >> ch && ch!='!') {
        s.push_back(ch);
    }
    std::cout << s << std::endl;
    
    return 0;
}
