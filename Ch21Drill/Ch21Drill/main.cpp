//
//  main.cpp
//  Ch21Drill
//
//  Created by Stefan Diaconu on 14/10/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include <vector>
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
        return (struct1.value > struct2.value);
    }
};

void found_name(vector<Item>& v, string s)
{
    auto p = find_if(v.begin(), v.end(), [&](Item a) { return a.name == s; });
    if (p != v.end())
        cout << "Item found" << endl;
    else
        cout << "Item not found" << endl;
}

void found_id(vector<Item>& v, int i)
{
    auto p = find_if(v.begin(), v.end(), [&](Item a) { return a.iid == i; });
    if (p != v.end())
        cout << "Item found" << endl;
    else
        cout << "Item not found" << endl;
}

void erase_item_name(vector<Item>& v, string s)
{
    auto p = find_if(v.begin(), v.end(), [&](Item a) { return a.name == s; });
    if (p != v.end())
        v.erase(p);
    else
        cout << "Item not found" << endl;
}

void erase_item_id(vector<Item>& v, int i)
{
    auto p = find_if(v.begin(), v.end(), [&](Item a) { return a.iid == i; });
    if (p != v.end())
        v.erase(p);
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
    
    vector<Item> vi;
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
        vi.push_back(item);
    }
    for (int i=0; i<vi.size(); ++i) {
        cout << vi[i].name << ", " << vi[i].iid << ", " << vi[i].value << endl;
    }
    
    cout << "Sort by name" <<  endl;
    sort(vi.begin(), vi.end(), less_than_name());
    for (int i=0; i<vi.size(); ++i) {
        cout << vi[i].name << ", " << vi[i].iid << ", " << vi[i].value << endl;
    }
    
    cout << "Sort by iid" << endl;
    sort(vi.begin(), vi.end(), less_than_iid());
    for (int i=0; i<vi.size(); ++i) {
        cout << vi[i].name << ", " << vi[i].iid << ", " << vi[i].value << endl;
    }
    
    cout << "Sort by value" << endl;
    sort(vi.begin(), vi.end(), less_than_value());
    for (int i=0; i<vi.size(); ++i) {
        cout << vi[i].name << ", " << vi[i].iid << ", " << vi[i].value << endl;
    }
    cout << endl;
    
    cout << "Before inserting" << endl;
    Item i1{"horse",99,12.34};
    vi.push_back(i1);
    Item i2{"Canon S400",9988,499.95};
    vi.push_back(i2);
    cout << "After inserting" << endl;
    
    cout << "Before removing" << endl;
    found_name(vi, "Tt");
    erase_item_name(vi, "Tt");
    erase_item_name(vi, "Yy");
    cout << "After removing" << endl;
    
    found_name(vi, "Tt");
    found_name(vi, "Yy");
    
    for (int i=0; i<vi.size(); ++i) {
        cout << vi[i].name << ", " << vi[i].iid << ", " << vi[i].value << endl;
    }
    cout << endl;
    
    cout << "Before removing" << endl;
    found_id(vi, 7);
    erase_item_id(vi, 7);
    erase_item_id(vi, 8);
    cout << "After removing" << endl;
    
    found_id(vi, 7);
    found_id(vi, 8);
    
    for (int i=0; i<vi.size(); ++i) {
        cout << vi[i].name << ", " << vi[i].iid << ", " << vi[i].value << endl;
    }
    cout << endl;
    
    return 0;
}
