//
//  main.cpp
//  Ch09-05
//
//  Created by Stefan Diaconu on 13/05/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "Book.h"
#include "Patron.h"

int main(int argc, char *argv[]) {
    // insert code here...
    Book book{"999-888-777-P","Moby Dick","Herman Melville","22.05.2018",Book::Genre::fiction};
    string checked_out = book.is_checked_out(false);

    cout << "Book ISBN: " <<  book.isbn() << ", book title: " << book.title() << ", book author: " << book.author() << ", book copyright date: " << book.copyright_date() << ", book checked out? " << checked_out << endl;
    
    cout << book << endl;
    
    Patron p{"stefan",1234};
    cout << "Username: " << p.username() << ", card number: " << p.card_number() << ", fee: " << p.library_fee() << endl;
    p.add_fee(3);
    cout << "Username: " << p.username() << ", card number: " << p.card_number() << ", fee: " << p.library_fee() << endl;
    
    return 0;
}
