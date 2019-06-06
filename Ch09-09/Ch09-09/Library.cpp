//
//  Library.cpp
//  Ch09-05
//
//  Created by Stefan Diaconu on 27/05/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "Library.h"

Library::Library()
{
}

Library::~Library()
{
}

void Library::add_books(Book& b) {
    book.push_back(b);
}

void Library::add_patrons(Patron& p) {
    patron.push_back(p);
}

void Library::add_transactions(Transaction& t) {
    transaction.push_back(t);
}

void Library::checkout_book(Book& b, Patron& p, Chrono::Date& d) {
    bool book = false;
    bool patron = false;
    for (int i=0; i<books().size(); ++i) {
        if ( b == books()[i] ) {
            book = true;
            //cout << "You can check out this book." << endl;
        }
    }
    
    for (int i=0; i<patrons().size(); ++i) {
        if ( p == patrons()[i] ) {
            patron = true;
            //cout << "The patron is registered with the library." << endl;
        }
    }
    
    if (book == true && patron == true) {
        cout << "The book is in the library and you are registered with the library." << endl;
        if (owe_fee(p)) {
            cout << "You cannot borough any book because you have an outstanding fee.\nPlease pay your fee first." << endl;
        }
        else {
            Transaction transaction{b, p, d};
            add_transactions(transaction);
        }
    }
    else if (book == true) {
        cout << "The book is available, but you are not registered with the library." << endl;
    }
    else if (patron == true) {
        cout << "The book is not available for checkout, but you are registered with the library." << endl;
    }
    else {
        cout << "The book is not available and you are not registered with the library." << endl;
    }
}

ostream& operator<<(ostream& os, const Library::Transaction& t)
{
    return os << "Username: " << t.p.username() << "\nCard number: " << t.p.card_number() << "\nBook: " << t.b.title();
}
