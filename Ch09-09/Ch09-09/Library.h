//
//  Library.h
//  Ch09-09
//
//  Created by Stefan Diaconu on 27/05/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#ifndef Library_h
#define Library_h
#include "Book.h"
#include "Patron.h"
#include "Chrono.h"
#include <vector>

class Library {
  
public:
    Library();
    ~Library();
    
    struct Transaction {
        Book b;
        Patron p;
        Chrono::Date d;
    };
    
    vector<Book> books() { return book; };
    vector<Patron> patrons() { return patron; };
    vector<Transaction> transactions() { return transaction; };
    
    void add_books(Book& b);
    void add_patrons(Patron& p);
    void checkout_book(Book& b, Patron& p, Chrono::Date& d);
    
private:
    vector<Book> book;
    vector<Patron> patron;
    vector<Transaction> transaction;
    void add_transactions(Transaction& t);
};

ostream& operator<<(ostream& os, const Library::Transaction& t);

#endif /* Library_h */
