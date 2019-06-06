//
//  Patron.cpp
//  Ch09-09
//
//  Created by Stefan Diaconu on 27/05/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "Patron.h"

Patron::Patron(string username, int card_number)
    :u_name(username), c_number(card_number)
{
}

Patron::Patron()
{
}

Patron::~Patron()
{
}

void Patron::add_fee(int add_fee)
{
    l_fee = add_fee;
}

bool owe_fee(Patron& p)
{
    if (p.library_fee() != 0) {
        return true;
    }
    else {
        return false;
    }
}

bool operator==(const Patron& a, const Patron& b)
{
    return a.username()==b.username();
}

bool operator!=(const Patron& a, const Patron& b)
{
    return !(a==b);
}

ostream& operator<<(ostream& os, const Patron& p)
{
    return os << "Username: " << p.username() << "\nCard number: " << p.card_number();
}

