//
//  main.cpp
//  Ch21DrillMap
//
//  Created by Stefan Diaconu on 24/10/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

bool is_int(const string& s)
{
    if (!s.empty() && std::find_if(s.begin(), s.end(), [](char c) { return !std::isdigit(c); }) == s.end())
        return true;
    else
        return false;
};

void read_to_map(map<string,int>& m)
{
    string s;
    int n;
    while (cin >> s >> n) {
        if (s == "|")
            break;
        m[s] = n;
    }
}

ostream& operator<<(ostream& os, map<string,int>& m)
{
    for (map<string,int>::iterator i = m.begin(); i != m.end(); ++i)
    {
        os << i->first << " : " << i->second << endl;
    }
    return os;
}

ostream& operator<<(ostream& os, map<int,string>& m)
{
    for (map<int,string>::iterator i = m.begin(); i != m.end(); ++i)
    {
        os << i->first << " : " << i->second << endl;
    }
    return os;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    map<string,int> msi;
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
        while (ss >> s) {
            if (is_int(s))
                i = stoi(s);
            else
                name = s;
        }
        msi[name] = i;
    }
    for (map<string,int>::iterator i = msi.begin(); i != msi.end(); ++i) {
        cout << i->first << ", " << i->second << endl;
    }
    cout << endl;
    
    cout << "Before removing" << endl;
    map<string,int>::iterator i = msi.find("Audi");
    if (i != msi.end())
        msi.erase(i);
    else
        cout << "Key not found" << endl;
    cout << "After removing" << endl;
    cout << endl;
    
    for (map<string,int>::iterator i = msi.begin(); i != msi.end(); ++i) {
        cout << i->first << ", " << i->second << endl;
    }
    cout << endl;
    
    cout << "Before reading" << endl;
    read_to_map(msi);
    cout << "After reading" << endl;
    
    for (map<string,int>::iterator i = msi.begin(); i != msi.end(); ++i) {
        cout << i->first << ", " << i->second << endl;
    }
    cout << endl;
    
    cout << msi << endl;
    cout << endl;
    
    int sum = 0;
    for (map<string,int>::iterator i = msi.begin(); i != msi.end(); ++i) {
        sum += i->second;
    }
    cout << "Sum: " << sum << endl;
    
    map<int,string> mis;
    for (map<string,int>::iterator i = msi.begin(); i != msi.end(); ++i) {
        mis[i->second] = i->first;
    }
    cout << endl;
    
    cout << mis << endl;
    
    return 0;
}
