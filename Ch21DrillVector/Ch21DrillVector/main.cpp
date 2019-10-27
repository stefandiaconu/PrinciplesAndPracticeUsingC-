//
//  main.cpp
//  Ch21DrillVector
//
//  Created by Stefan Diaconu on 26/10/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

bool is_double(const string& s)
{
    try {
        stod(s);
    } catch (exception e) {
        return false;
    }
    return true;
}

ostream& operator<<(ostream& os, vector<double>& vd)
{
    for (int i=0; i<vd.size(); ++i) {
        os << vd[i] << "\n";
    }
    return os;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<double> vd;
    ifstream ifs;
    string line;
    ifs.open("drill.txt",ios_base::out);
    if (ifs.is_open())
        cout << "File is opened" << endl;
    while (getline(ifs,line)) {
        stringstream ss;
        string s;
        double d = 0.0;
        ss.str(line);
        while (ss >> s) {
            if (is_double(s))
                d = stod(s);
            vd.push_back(d);
        }
    }
    cout << vd <<endl;
    cout << endl;
    
    vector<int> vi;
    for (int i=0; i<vd.size(); ++i)
        vi.push_back(vd[i]);
    
    for (int i=0; i<vd.size(); ++i) {
        cout << vd[i] << ", " << vi[i] << endl;
    }
    cout << endl;
    double sumd = 0.0;
    for (int i=0; i<vd.size(); ++i) {
        sumd += vd[i];
    }
    cout << "Sum of vector<double>: " << sumd << endl;
    cout << endl;
    
    double sumi = 0;
    for (int i=0; i<vi.size(); ++i) {
        sumi += vi[i];
    }
    cout << "Sum of vector<int>: " << sumi << endl;
    cout << endl;
    cout << "Difference between sum of vector<double> and sum of vector<int>: " << sumd - sumi << endl;
    cout << endl;

    reverse(vd.begin(), vd.end());
    cout << vd << endl;
    
    double sum_mean = 0.0;
    double mean = 0.0;
    // mean
    for (int i=0; i<vd.size(); ++i) {
        sum_mean += vd[i];
    }
    mean = sum_mean / vd.size();
    cout << "Mean of vd: " << mean << endl;
    
    vector<double> vd2;
    for (int i=0; i<vd.size(); ++i) {
        if (vd[i] < mean)
            vd2.push_back(vd[i]);
    }
    cout << endl;
    cout << vd2 << endl;
    cout << endl;
    
    sort(vd.begin(), vd.end());
    cout << vd << endl;
    
    return 0;
}
