//
//  Book.h
//  Ch09-05
//
//  Created by Stefan Diaconu on 13/05/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#ifndef Book_h
#define Book_h
#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    Book(std::string i, std::string t, std::string a, std::string copyright);
    Book();
    ~Book();
    
    string isbn() const;
    string title() const { return t; };
    string author() const { return a; };
    string copyright_date() const { return copyright; };
    
    string is_checked_out(bool is_checked);
private:
    string i;                   // isbn
    string t;                   // title
    string a;                   // author
    string copyright;           // copyright date
};

bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);
ostream& operator<<(ostream& os, const Book& a);

#endif /* Book_h */
