//
//  main.cpp
//  Ch10-02
//
//  Created by Stefan Diaconu on 19/06/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "../../std_lib_facilities.h"

struct Reading {
    int hour;
    double temperature;
    Reading (int h, double t) : hour(h),temperature(t) {};
    Reading () : hour(),temperature() {};
};

ostream& operator<<(ostream& os, const Reading& r) {
    return os << r.hour << ',' << r.temperature << '\n';
}

istream& operator>>(istream& is, Reading& r)
{
    int hour;
    double temperature;
    char ch;
    is >> hour >> ch >> temperature;
    if (!is) return is;
    if (ch != ',') {
        is.clear(ios_base::failbit);
        return is;
    }
    r = Reading{hour,temperature};
    return is;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ofstream ost;
    ost.open("raw_temps.txt",ios_base::in | ios_base::app);
    vector<Reading> raw_temps;
    int n = 0;
    while (n < 50) {
        int hour = rand() % 24;
        double temperature = rand() % 50 + rand() % 10;
        ost << Reading{hour,temperature};
        n++;
    }
    ost.close();
    cout << n << endl;
    
    cout << endl;

    vector<Reading> temps;
    ifstream ist;
    ist.open("raw_temps.txt",ios_base::out);
    for (int i=0; i<n; ++i) {
        Reading r;
        ist >> r;
        temps.push_back(r);
    }
    ist.close();
    
    for (int i=0; i<temps.size(); ++i) {
        cout << temps[i] << endl;
    }
    
    return 0;
}
