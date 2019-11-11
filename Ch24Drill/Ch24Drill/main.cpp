//
//  main.cpp
//  Ch24Drill
//
//  Created by Stefan Diaconu on 05/11/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <complex>
#include <cerrno>
#include <iomanip>
#include "../../Matrix.h"
using namespace std;
using namespace Numeric_lib;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << sizeof(char) << endl;
    cout << sizeof(short) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(double) << endl;
    cout << sizeof(int*) << endl;
    cout << sizeof(double*) << endl;
    
    cout << endl;
    
    Matrix<int> a(10);
    cout << sizeof(a) << endl;
    Matrix<int> b(100);
    cout << sizeof(b) << endl;
    Matrix<double> c(10);
    cout << sizeof(c) << endl;
    Matrix<int,2> d(10,10);
    cout << sizeof(d) << endl;
    Matrix<int,3> e(10,10,10);
    cout << sizeof(e) << endl;
    
    cout << endl;
    
    cout << a.size() << endl;
    cout << b.size() << endl;
    cout << c.size() << endl;
    cout << d.size() << endl;
    cout << e.size() << endl;
    
//    // 4
//    int n;
//    while(cin >> n) {
//        if (n != '|') {
//            if (n < 0) {
//                cout << "To take the square root of a number it must be positive, n is " << n << endl;
//            }
//            else{
//                cout << "The square root of " << n << " is " << sqrt(n) << endl;
//            }
//        }
//    }
    
//    // 5
//    Matrix<double> matrix(10);
//    double m;
//    for (int i=0; i<10; ++i) {
//        cin >> m;
//        matrix[i] = m;
//    }

//    cout << endl;
//
//    for (int i=0; i<matrix.dim1(); ++i)
//        cout << matrix[i] << endl;
    
//    // 6
//    int n;
//    cin >> n;
//    int m;
//    cin >> m;
//    Matrix<int,2> mtable(n,m);
//    for (Index i = 0; i<mtable.dim1(); ++i) {
//        for (Index j = 0; j<mtable.dim2(); ++j) {
//            mtable(i,j) = (i+1)*(j+1);
//            cout << setw(5) << mtable(i,j);
//        }
//        cout << '\n';
//    }
    
//    // 7
//    Matrix<complex<double>> m_complex(10);
//    complex<double> n;
//    for (int i=0; i<10; ++i) {
//        cin >> n;
//        m_complex[i] = n;
//    }
//
//    for (int i=0; i<m_complex.size(); ++i)
//        cout << m_complex[i] << endl;
    
    // 8
    int n;
    Matrix<int,2> m(2,3);
    for (int i=0; i<m.dim1(); ++i) {
        for (int j=0; j<m.dim2(); ++j) {
            cin >> n;
            m(i,j) = n;
        }
    }
    
    for (int i=0; i<m.dim1(); ++i) {
        for (int j=0; j<m.dim2(); ++j) {
            cout << setw(5)  << m(i,j);
        }
        cout << "\n";
    }
    
    cout << endl;
    
    return 0;
}
