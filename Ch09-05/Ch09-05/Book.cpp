//
//  Book.cpp
//  Ch09-05
//
//  Created by Stefan Diaconu on 13/05/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "Book.h"
#include <regex>

Book::Book(string ii, string tt, string aa, string copyright, Genre gen)
    :i(ii), t(tt), a(aa), copyright(copyright), gen(gen)
{
}

Book::Book()
{
}

Book::~Book()
{
}

string Book::is_checked_out(bool is_checked)
{
    string checked_out;
    if (is_checked)
        checked_out = "Yes";
    else
        checked_out = "No";
    return checked_out;
}

string Book::isbn() const
{
    if (regex_match(i, regex("(\\+)?[[:digit:]]+(\\-)(\\+)?[[:digit:]]+(\\-)(\\+)?[[:digit:]]+(\\-)(\\d|[A-Z])")))
        return i;
    else
        return "Not a valid ISBN";
}

bool operator==(const Book& a, const Book& b)
{
    return a.isbn()==b.isbn();
}

bool operator!=(const Book& a, const Book& b)
{
    return !(a==b);
}

ostream& operator<<(ostream& os, const Book& a)
{
    string type;
    switch (a.genre()) {
        case 1:
            type = "fiction";
            break;
        case 2:
            type = "nonfiction";
            break;
        case 3:
            type = "periodical";
            break;
        case 4:
            type = "biography";
            break;
        case 5:
            type = "children";
            break;
            
        default:
            type = "Not a genre";
            break;
    }
    return os << "Title: " << a.title() << "\nAuthor: " << a.author() << "\nISBN: " << a.isbn() << "\nGenre: " << type;
}
