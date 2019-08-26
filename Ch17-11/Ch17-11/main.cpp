//
//  main.cpp
//  Ch17-11
//
//  Created by Stefan Diaconu on 22/08/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
using namespace std;

struct God {
    string name;
    string mythology;
    string vehicle;
    string weapon;
};

class Link {
public:

    God value;
    
    Link(const string& n, const string& m, const string& v, const string& w, Link* p = nullptr, Link* s = nullptr)
    : value{n,m,v,w}, prev{p}, succ{s} {}
    
    Link* insert(Link* n);                      // insert 'n' before this object
    Link* add(Link* n);                         // insert 'n' after this object
    Link* erase(Link* n);                       // remove this object from list
    Link* find(Link* n, const string& s);       // find 's' in list
    
    Link* advance(Link* p, int n) const;        // move 'n' positions in list
    
    Link* next() const { return succ; }
    Link* previous() const { return prev; }
    
private:
    Link* prev;
    Link* succ;
};

Link* Link::insert(Link* n)                     // insert 'n' before p; return 'n'
{
    //Link* p = this;                           // pointer to this object
    if (n==nullptr) return this;                // nothing to insert
    if (this==nullptr) return n;                // nothing to insert into
    n->succ = this;                             // 'p' comes after 'n'
    if (prev) prev->succ = n;
    n->prev = prev;                             // 'p's predecessor becomes 'n's predecessor
    prev = n;                                   // 'n' becomes 'p's predecessor
    
    return n;
};

Link* Link::add(Link *n)
{
    return n;
};

Link* Link::erase(Link* n)
{
    if (n==nullptr) return nullptr;
    if (n->succ) n->succ->prev = n->prev;
    if (n->prev) n->prev->succ = n->succ;
    return n->succ;
};

Link* Link::find(Link* p, const string &s)
{
    while (p) {
        if (p->value.name == s) return p;
        p = p->succ;
    }
    return nullptr;
};

Link* Link::advance(Link *p, int n) const
{
    if (p==nullptr) return nullptr;
    if (0<n) {
        while (n--) {
            if (p->succ == nullptr) return nullptr;
            p = p->succ;
        }
    }
    else if (n<0) {
        while (n++) {
            if (p->prev == nullptr) return nullptr;
            p = p->prev;
        }
    }
    return p;
};

void print_all(Link* p)
{
    cout << "{\n";
    while(p) {
        cout << "\t" << p->value.name << ", " << p->value.mythology << ", " << p->value.vehicle << ", " << p->value.weapon;
        if (p=p->next()) cout << "\n";
    }
    cout << "\n}";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Link* norse_gods = new Link{"Thor","Norse","none","Hammer Mjolnir"};
    norse_gods = norse_gods->insert(new Link{"Odin","Norse","Eight-legged horse called Sleipner","Spear called Gungnir"});
    norse_gods = norse_gods->insert(new Link{"Zeus","Greek","none","lightning"});
    norse_gods = norse_gods->insert(new Link{"Freia","Noorse","Chariot pulled by two cats","Necklace Brísingamen"});
    
    Link* greek_gods = new Link{"Hera","Greek","Golden sandals","Thunderbolt"};
    greek_gods = greek_gods->insert(new Link{"Athena","Greek","none","none"});
    greek_gods = greek_gods->insert(new Link{"Mars","Roman","none","none"});
    greek_gods = greek_gods->insert(new Link{"Poseidon","Greek","none","Trident"});
    
    Link* p = greek_gods->find(greek_gods, "Mars");
    if (p) { p->value.name = "Ares"; p->value.mythology = "Greek"; }
    
    Link* p2 = norse_gods->find(norse_gods, "Zeus");
    if (p2) {
        if (p2==norse_gods) norse_gods = p2->next();
        p2->erase(p2);
        greek_gods = greek_gods->insert(p2);
    }
    
    print_all(norse_gods);
    cout << "\n";
    print_all(greek_gods);
    cout << "\n";
    
    return 0;
}
