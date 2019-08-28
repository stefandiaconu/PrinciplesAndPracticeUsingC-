//
//  main.cpp
//  Ch18-01
//
//  Created by Stefan Diaconu on 26/08/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
using namespace std;

// Ch18-01
char* strdup(const char* s)
{
    if (s==0) return 0;
    // get the number of char in s
    int n = 0;
    while (s[n] != 0)
        ++n;
    
    // allocate memory with room for terminating 0
    char* ss = new char[n+1];
    
    // copy string
    for (int i=0; s[i]; ++i)
        ss[i] = s[i];
    
    ss[n] = 0;
    
    
    return ss;
}

// Ch18-02
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

// Ch18-03
int strcmp(const char* s1, const char* s2)
{
    if (*s1<*s2)
        return -1;
    else if (*s1==*s2)
        return 0;
    else
        return 1;
}

// Ch18-05
string cat_dot(const string& s1, const string& s2)
{
    string str = "";
    str.append(s1);
    str.append(".");
    str.append(s2);
    return str;
}

// Ch18-06
string cat_dot(const string& s1, const string& s2, const string& s3)
{
    string str = "";
    str.append(s1);
    str.append(s3);
    str.append(s2);
    return str;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    // Ch18-01
//    char str[0];
//    char* s;
//    while (cin>>str) {
//        s = strdup(str);
//        cout << s << endl;
//        delete [] s;
//    }
    
//    // Ch18-02
//    char s[] = "The quick brown fox jumps over the lazy dog";
//    char x[] = "fox";
//    const char* result = findx(s, x);
//    cout << result << endl;
    
//    // Ch18-03
//    char* s1 = (char*)"fox";
//    char* s2 = (char*)"dog";
//    int n = strcmp(s1, s2);
//    cout << n << endl;
    
    // Ch18-05
    string s1 = "Niels";
    string s2 = "Bohr";
    string str = cat_dot(s1, s2);
    cout << str << endl;
    
    // Ch18-06
    string s3 = "Niels";
    string s4 = "Bohr";
    string s5 = "::";
    string str2 = cat_dot(s3, s4, s5);
    cout << str2 << endl;
    
    return 0;
}
