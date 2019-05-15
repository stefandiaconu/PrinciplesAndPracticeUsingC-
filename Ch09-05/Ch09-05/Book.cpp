//
//  Book.cpp
//  Ch09-05
//
//  Created by Stefan Diaconu on 13/05/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "Book.h"
#include <regex>
using namespace std;

Book::Book(string ii, string tt, string aa, string copyright)
    :i(ii), t(tt), a(aa), copyright(copyright)
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
