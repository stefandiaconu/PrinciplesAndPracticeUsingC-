//
//  main.cpp
//  Ch08-13
//
//  Created by Stefan Diaconu on 29/04/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include "../../std_lib_facilities.h"

// find the number of characters of each string from array of strings
vector<int> numberOfCharacters(vector<string> v)
{
    vector<int> no;
    int count = 0;
    
    for (string s : v) {
        for (int i = 0; i < s.size(); ++i) {
            count++;
        }
        no.push_back(count);
        count = 0;
    }
    
    return no;
}

// find the shortest string from array of strings
string shortestString(vector<string> v)
{
    string shortest;
    vector<int> no = numberOfCharacters(v);
    int small = no[0];
    int index = 0;
    for (int i = 0; i < no.size(); ++i) {
        if (no[i] < small) {
            small = no[i];
            index = i;
        }
    }
    
    shortest = v[index];
    
    return shortest;
}

// find the longest string from array of strings
string longestString(vector<string> v)
{
    string longest;
    vector<int> no = numberOfCharacters(v);
    int max = no[0];
    int index = 0;
    for (int i = 0; i < no.size(); ++i) {
        if (no[i] > max) {
            max = no[i];
            index = i;
        }
    }
    
    longest = v[index];
    
    return longest;
}

// find the first string in lexical order from array of strings
string firstString(vector<string> v)
{
    string first;
    sort(v.begin(), v.end());
    first = v[0];
    
    return first;
}

// find the last string in lexical order from array of strings
string lastString(vector<string> v)
{
    string last;
    sort(v.begin(), v.end());
    last = v[(int)(v.size()-1)];
    
    return last;
}

int main() {
    // insert code here...
    vector<string> v = {"alpha","beta","gamma","pi","phi","chi","delta","alphaomega","kappa","zeta","sigma","theta","delta","omega"};
    vector<int> no = numberOfCharacters(v);
    string shortest = shortestString(v);
    string longest = longestString(v);
    string first = firstString(v);
    string last = lastString(v);
    
    for (int i = 0; i < no.size(); ++i) {
        cout << no[i] << endl;
    }
    
    cout << shortest << endl;
    cout << longest << endl;
    cout << first << endl;
    cout << last << endl;
    
    return 0;
}
