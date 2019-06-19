//
//  main.cpp
//  Ch10-03
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
    return os << '(' << r.hour << ',' << r.temperature << ')';
}

istream& operator>>(istream& is, Reading& r)
{
    int hour;
    double temperature;
    char ch1, ch2, ch3;
    is >> ch1 >> hour >> ch2 >> temperature >> ch3;
    if (!is) return is;
    if (ch1 != '(' || ch2 != ',' || ch3 != ')') {
        is.clear(ios_base::failbit);
        return is;
    }
    r = Reading{hour,temperature};
    return is;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ofstream ost;
    ost.open("raw_temps.txt",ios_base::out);
    vector<Reading> raw_temps;
    int n = 0;
    while (n < 50) {
        // trully random number
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(0,24);
        int hour = dist(mt);
        // trully random number
        std::random_device rd2;
        std::mt19937 mt2(rd2());
        std::uniform_int_distribution<int> dist2(-43,107);
        std::random_device rd3;
        std::mt19937 mt3(rd3());
        std::uniform_int_distribution<int> dist3(0,9);
        double temperature = dist2(mt2) + dist3(mt3)/double(10);
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
    
    // calculate mean
    vector<double> temps2;
    for (int i=0; i<temps.size(); ++i) {
        temps2.push_back(temps[i].temperature);
    }
    
    double mean;
    double sum = 0.0;
    for (double n: temps2) {
        sum += n;
    }
    mean = sum / temps2.size();
    cout << "Sum: " << sum << endl;
    cout << "Mean: " << mean << endl;
    
    // calculate median
    cout << "25: " << temps2[round(temps2.size() / 2)] << ", 26: " << temps2[round(temps2.size() / 2) + 1] << endl;
    cout << "25: " << temps2[25] << endl;
    cout << "26: " << temps2[26] << endl;
    double median = (temps2[round(temps2.size() / 2)] + temps2[round(temps2.size() / 2) + 1]) / 2;
    cout << "Median: " << median << endl;
    
    return 0;
}
