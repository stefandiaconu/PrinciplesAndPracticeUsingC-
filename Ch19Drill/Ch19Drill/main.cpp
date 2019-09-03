//
//  main.cpp
//  Ch19Drill
//
//  Created by Stefan Diaconu on 28/08/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

template<typename T> struct S
{
public:
    S() : val{T()} {}
    S(T v) : val{v} {}

    T& get();
    const T& get() const;
    void set(const T& d);
    
    S& operator=(const T& d);
    
    void read_val(T& v);
private:
    T val;
};

template<typename T> T& S<T>::get() { return val; };

template<typename T> const T& S<T>::get() const { return val; };

template<typename T> void S<T>::set(const T &d) { val = d; };

template<typename T> S<T>& S<T>::operator=(const T &d) { return S().set(d); };

template<typename T> void S<T>::read_val(T &v) { cin>>v; val = v; };

int main(int argc, const char * argv[]) {
    // insert code here...
    
    S<int> s_int(7);
    S<char> s_char('x');
    S<double> s_double(2.3);
    S<string> s_string("Hello");
    vector<int> vi;
    vi.push_back(1);
    vi.push_back(2);
    vi.push_back(3);
    S<vector<int>> s_vector(vi);
    for (int i=0; i<vi.size(); ++i)
        cout << s_vector.get()[i] << endl;
    
    cout << endl;
    cout << s_int.get() << endl;
    cout << s_char.get() << endl;
    cout << s_double.get() << endl;
    cout << s_string.get() << endl;
    cout << endl;
    
    int n;
    S<int> s1;
    s1.read_val(n);
    cout << s1.get() << endl;
    char ch;
    S<char> s2;
    s2.read_val(ch);
    cout << s2.get() << endl;
    double d;
    S<double> s3;
    s3.read_val(d);
    cout << s3.get() << endl;
    string s;
    S<string> s4;
    s4.read_val(s);
    cout << s4.get() << endl;
    
    return 0;
}
