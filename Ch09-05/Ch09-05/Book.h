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
    
    enum Genre {
        fiction = 1, nonfiction, periodical, biography, children
    };
    
    Book(std::string i, std::string t, std::string a, std::string copyright, Genre gen);
    Book();
    ~Book();
    
    string isbn() const;
    string title() const { return t; };
    string author() const { return a; };
    string copyright_date() const { return copyright; };
    Genre genre() const { return gen; };
    
    string is_checked_out(bool is_checked);
private:
    string i;                   // isbn
    string t;                   // title
    string a;                   // author
    string copyright;           // copyright date
    Genre gen;
};

bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);
ostream& operator<<(ostream& os, const Book& a);

#endif /* Book_h */
