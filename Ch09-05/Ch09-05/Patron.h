//
//  Patron.h
//  Ch09-05
//
//  Created by Stefan Diaconu on 27/05/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#ifndef Patron_h
#define Patron_h
#include <string>
using namespace std;

class Patron {
  
public:
    Patron(string u_name, int c_number);
    Patron();
    ~Patron();
    
    string username() const { return u_name; };
    int card_number() const { return c_number; };
    int library_fee() { return l_fee; };
    
    void add_fee(int add_fee);
    
private:
    string u_name;
    int c_number;
    int l_fee;
};

bool owe_fee(Patron& p);

#endif /* Patron_h */
