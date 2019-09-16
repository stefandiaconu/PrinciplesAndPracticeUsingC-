//
//  main.cpp
//  Ch19-01
//
//  Created by Stefan Diaconu on 03/09/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// Ch19-01
template <typename T>
void f(vector<T>& v1, vector<T>& v2)
{
    for (int i=0; i<v1.size(); ++i) {
        v1[i]+=v2[i];
    }
}

// Ch19-02
template <typename T>
vector<T> f2(vector<T>& vt, vector<T>& vu)
{
    vector<T> sum;
    for (int i=0; i<vt.size(); ++i) {
        sum.push_back(vt[i]*vu[i]);
    }
    return sum;
}

// Ch19-03
template <class T, class U>
class Pair {
public:
    Pair(T t, U u) : t{t}, u{u} {}
    T t;
    U u;
};

class Symbol_table
{
    vector<Pair<char, string>> var_table;
public:
    string get(char ch);
    void set(char ch, string s);
    bool contains(char ch);
    void add(char ch, string s);
    void print();
};

string Symbol_table::get(char ch)
{
    for (int i=0; i<var_table.size(); ++i)
        if (var_table[i].t == ch) return var_table[i].u;
    return "Character not in the list!";
}

void Symbol_table::set(char ch, string s)
{
    for (int i=0; i<var_table.size(); ++i){
        if (var_table[i].t == ch){
            var_table[i].u = s;
            return;
        }
    }
    cout << "Character not in list" << endl;
}

bool Symbol_table::contains(char ch)
{
    for (int i=0; i<var_table.size(); ++i)
        if (var_table[i].t == ch) return true;
    return false;
}

void Symbol_table::add(char ch, string s)
{
    if (contains(ch)) cout << "Character already in the list" << endl;
    var_table.push_back(Pair<char, string>(ch,s));
}

void Symbol_table::print()
{
    for (int i=0; i<var_table.size(); ++i)
        cout << "Character: " << var_table[i].t << ", description: " << var_table[i].u << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    // Ch19-01
//    vector<string> v1{"a","c","e"};
//    vector<string> v2{"b","d","f"};
//    f(v1,v2);
//    for (string x : v1)
//        cout << x << endl;
    
//    // Ch19-02
//    vector<int> vt{1,2,3};
//    vector<int> vu{2,2,2};
//    vector<int> sum = f2(vt, vu);
//    for (int x : sum)
//        cout << x << endl;
    
    // Ch19-03
    Symbol_table sb;
    sb.add('+', "plus");
    sb.add('-', "minus");
    sb.add('*', "multiplication");
    sb.add('/', "division");
    sb.add('%', "modulo");
    
    sb.print();
    
    bool b = sb.contains('*');
    cout << b << endl;
    
    sb.set('*', "multiply");
    sb.print();
    
    string s = sb.get('+');
    cout << s << endl;
    
    return 0;
}
