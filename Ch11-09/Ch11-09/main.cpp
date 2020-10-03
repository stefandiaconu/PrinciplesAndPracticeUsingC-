//
//  main.cpp
//  Ch11-09
//
//  Created by Stefan Diaconu on 30/09/2020.
//

#include <iostream>
#include <fstream>
#include "../../std_lib_facilities.h"
using namespace std;

vector<int> binary_in(const string& fname)
    // read in a file and store as binary in vector
{
    ifstream ifs {fname, ios_base::binary};
    if (!ifs) error("can't read from file ", fname);

    vector<int> v;

    for (int x; ifs.read(as_bytes(x), sizeof(int)); )
        v.push_back(x);

    return v;
}

void binary_out(const string& fname, const vector<int>& v)
    // write out to a file from binary
{
    ofstream ofs {fname, ios_base::binary};
    if (!ofs) error("could not write to file ", fname);

    for (int x : v)
        ofs.write(as_bytes(x), sizeof(int));
}

int main(int argc, const char * argv[]) {
    
    // open an istream for binary input from a file:
    cout << "Please enter input file name\n";
    string iname;
    cin >> iname;
    vector<int> bin = binary_in(iname);

    // open an ostream for binary output to a file:
    cout << "Please enter output file name\n";
    string oname;
    cin >> oname;
    binary_out(oname, bin);
    
    return 0;
}
