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

class Book {
public:
    Book(std::string i, std::string t, std::string a, std::string copyright);
    Book();
    ~Book();
    
    std::string isbn() const;
    std::string title() const { return t; };
    std::string author() const { return a; };
    std::string copyright_date() const { return copyright; };
    
    std::string is_checked_out(bool is_checked);
private:
    std::string i;                   // isbn
    std::string t;                   // title
    std::string a;                   // author
    std::string copyright;           // copyright date
};

#endif /* Book_h */
