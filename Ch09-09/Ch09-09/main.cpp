//
//  main.cpp
//  Ch09-09
//
//  Created by Stefan Diaconu on 27/05/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "Library.h"

int main() {
    // insert code here...
    Book book1 {"111-111-111-A","Moby Dick","Herman Melville","22.05.2018",Book::Genre::fiction};
    cout << book1 << endl;
    Book book2 {"111-222-111-A","The Adventures of Tom Sawyer","Mark Twain","17.03.1876",Book::Genre::fiction};
    cout << book2 << endl;
    Book book3 {"111-333-111-A","Adventures of Huckleberry Finn","Mark Twain","06.12.1885",Book::Genre::fiction};
    cout << book3 << endl;
    Book book4 {"111-444-111-A","Around the World in Eighty Days","Jules Verne","30.01.1873",Book::Genre::fiction};
    cout << book4 << endl;
    Book book5 {"111-555-111-A","The Three Musketeers","Alexandre Dumas","03.03.1844",Book::Genre::fiction};
    cout << book5 << endl;
    
    cout << endl;
    
    Patron patron1{"username1",12341};
    Patron patron2{"username2",12342};
    Patron patron3{"username3",12343};
    Patron patron4{"username4",12344};
    Patron patron5{"username5",12345};
    
    cout << "Username: " << patron1.username() << ", card number: " << patron1.card_number() << endl;
    cout << "Username: " << patron2.username() << ", card number: " << patron2.card_number() << endl;
    cout << "Username: " << patron3.username() << ", card number: " << patron3.card_number() << endl;
    cout << "Username: " << patron4.username() << ", card number: " << patron4.card_number() << endl;
    cout << "Username: " << patron5.username() << ", card number: " << patron5.card_number() << endl;
    
    cout << endl;
    
    Library library;
    library.add_books(book1);
    library.add_books(book2);
    library.add_books(book3);
    library.add_books(book4);
    library.add_books(book5);
    
    for (int i=0; i<library.books().size(); ++i) {
        cout << library.books()[i] << endl;
    }
    
    cout << endl;
    
    library.add_patrons(patron1);
    library.add_patrons(patron2);
    library.add_patrons(patron3);
    library.add_patrons(patron4);
    library.add_patrons(patron5);
    
    for (int i=0; i<library.patrons().size(); ++i) {
        cout << library.patrons()[i] << endl;
    }
    
    cout << endl;
    
    Library::Transaction t1;
    t1.b = book2;
    t1.p = patron2;
    t1.d = {2018,Chrono::Month::feb,17};

    Library::Transaction t2;
    t2.b = book3;
    t2.p = patron4;
    t2.d = {2017,Chrono::Month::mar,20};
    
    Library::Transaction t3;
    t3.b = book1;
    t3.p = patron5;
    t3.d = {2016,Chrono::Month::jul,12};
    
//    library.add_transactions(t1);
//    library.add_transactions(t2);
//    library.add_transactions(t3);
    
    for (int i=0; i<library.transactions().size(); ++i) {
        cout << library.transactions()[i] << endl;
    }
    
    cout << endl;
    
    Book book6 {"111-666-111-A","Divine Comedy","Dante Alleghieri","01.01.1320",Book::Genre::fiction};
    cout << book5 << endl;
    
    Patron patron6{"username6",12346};
    cout << patron6 << endl;
    
    Chrono::Date d{2005,Chrono::Month::feb,29};
    
    cout << endl;
    
    patron1.add_fee(0);
    patron2.add_fee(2);
    patron3.add_fee(0);
    patron4.add_fee(0);
    patron5.add_fee(5);
    patron6.add_fee(0);
    
    cout << endl;
    
    library.checkout_book(book2, patron1, d);
    library.checkout_book(book2, patron6, d);
    library.checkout_book(book5, patron4, d);
    library.checkout_book(book6, patron6, d);
    library.checkout_book(book1, patron5, d);
    library.checkout_book(book4, patron2, d);
    library.checkout_book(book3, patron2, d);
    
    cout << endl;
    
    for (int i=0; i<library.transactions().size(); ++i) {
        cout << library.transactions()[i] << endl;
    }
    
    return 0;
}
