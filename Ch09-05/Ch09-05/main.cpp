//
//  main.cpp
//  Ch09-05
//
//  Created by Stefan Diaconu on 13/05/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include "Book.h"

int main() {
    // insert code here...
    Book book = {"999-888-777-P","Moby Dick","Herman Melville","22.05.2018"};
    std::string checked_out = book.is_checked_out(false);

    std::cout << "Book ISBN: " <<  book.isbn() << ", book title: " << book.title() << ", book author: " << book.author() << ", book copyright date: " << book.copyright_date() << ", book checked out? " << checked_out << std::endl;
    
    return 0;
}
