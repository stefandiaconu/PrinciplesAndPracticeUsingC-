//
//  main.cpp
//  Ch21DrillList
//
//  Created by Stefan Diaconu on 23/10/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
using namespace std;

struct Item
{
    string name;
    int iid;
    double value;
    
    Item(string n, int i, double v) : name{n}, iid{i}, value{v} {}
    Item() : name{""}, iid{0}, value{0.0} {}
};

struct less_than_name
{
    inline bool operator() (const Item& struct1, const Item& struct2)
    {
        return (struct1.name < struct2.name);
    }
};

struct less_than_iid
{
    inline bool operator() (const Item& struct1, const Item& struct2)
    {
        return (struct1.iid < struct2.iid);
    }
};

struct less_than_value
{
    inline bool operator() (const Item& struct1, const Item& struct2)
    {
        return (struct1.value < struct2.value);
    }
};

void found_name(list<Item>& l, string s)
{
    auto p = find_if(l.begin(), l.end(), [&](Item a) { return a.name == s; });
    if (p != l.end())
        cout << "Item found" << endl;
    else
        cout << "Item not found" << endl;
}

void found_id(list<Item>& l, int i)
{
    auto p = find_if(l.begin(), l.end(), [&](Item a) { return a.iid == i; });
    if (p != l.end())
        cout << "Item found" << endl;
    else
        cout << "Item not found" << endl;
}

void erase_item_name(list<Item>& l, string s)
{
    auto p = find_if(l.begin(), l.end(), [&](Item a) { return a.name == s; });
    if (p != l.end())
        l.erase(p);
    else
        cout << "Item not found" << endl;
}

void erase_item_id(list<Item>& l, int i)
{
    auto p = find_if(l.begin(), l.end(), [&](Item a) { return a.iid == i; });
    if (p != l.end())
        l.erase(p);
    else
        cout << "Item not found" << endl;
}


bool is_int(const string& s)
{
    if (!s.empty() && std::find_if(s.begin(), s.end(), [](char c) { return !std::isdigit(c); }) == s.end())
        return true;
    else
        return false;
};

bool is_double(const string& s)
{
    try {
        stod(s);
    }
    catch (exception& e) {
        return false;
    }
    return true;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    list<Item> li;
    ifstream ifs;
    string line;
    ifs.open("drill1.txt",ios_base::out);
    if (ifs.is_open())
        cout << "File is opened" << endl;
    while(getline(ifs,line)) {
        stringstream ss;
        ss.str(line);
        string s = "";
        string name = "";
        int i = 0;
        double d = 0.0;
        while (ss >> s) {
            if (is_int(s))
                i = stoi(s);
            else if (is_double(s))
                d = stod((s));
            else
                name = s;
        }
        Item item{name,i,d};
        li.push_back(item);
    }
    for (list<Item>::iterator i = li.begin(); i != li.end(); ++i) {
        cout << i->name << ", " << i->iid << ", " << i->value << endl;
    }
    
    cout << "Sort by name" <<  endl;
    li.sort(less_than_name());
    for (list<Item>::iterator i = li.begin(); i != li.end(); ++i) {
        cout << i->name << ", " << i->iid << ", " << i->value << endl;
    }
    
    cout << "Sort by iid" << endl;
    li.sort(less_than_iid());
    for (list<Item>::iterator i = li.begin(); i != li.end(); ++i) {
        cout << i->name << ", " << i->iid << ", " << i->value << endl;
    }
    
    cout << "Sort by value" << endl;
    li.sort(less_than_value());
    for (list<Item>::iterator i = li.begin(); i != li.end(); ++i) {
        cout << i->name << ", " << i->iid << ", " << i->value << endl;
    }
    cout << endl;
    
    cout << "Before inserting" << endl;
    Item i1{"horse",99,12.34};
    li.push_back(i1);
    Item i2{"Canon S400",9988,499.95};
    li.push_back(i2);
    cout << "After inserting" << endl;
    
    
    found_name(li, "Tt");
    erase_item_name(li, "Tt");
    erase_item_name(li, "Yy");
    cout << "After removing" << endl;
    
    found_name(li, "Tt");
    found_name(li, "Yy");
    
    for (list<Item>::iterator i = li.begin(); i != li.end(); ++i) {
        cout << i->name << ", " << i->iid << ", " << i->value << endl;
    }
    cout << endl;
    
    cout << "Before removing" << endl;
    found_id(li, 7);
    erase_item_id(li, 7);
    erase_item_id(li, 8);
    cout << "After removing" << endl;
    
    found_id(li, 7);
    found_id(li, 8);
    
    for (list<Item>::iterator i = li.begin(); i != li.end(); ++i) {
        cout << i->name << ", " << i->iid << ", " << i->value << endl;
    }
    cout << endl;
    
    return 0;
}
