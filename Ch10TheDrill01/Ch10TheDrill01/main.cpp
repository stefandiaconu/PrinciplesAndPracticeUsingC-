//
//  main.cpp
//  Ch10TheDrill01
//
//  Created by Stefan Diaconu on 16/06/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "../../std_lib_facilities.h"

class Point {

public:
    Point() : x(), y() {};
    Point(int x_v, int y_v) : x(x_v), y(y_v) {};
    ~Point() {};
    int x_value() const { return x; }
    int y_value() const { return y; };

private:
    int x;
    int y;
};

ostream& operator<<(ostream& os, const Point& p) {
    return os << '(' << p.x_value() << ',' << p.y_value() << ')';
}

istream& operator>>(istream& is, Point& p)
{
    int x, y;
    char ch1, ch2, ch3;
    is >> ch1 >> x >> ch2 >> y >> ch3;
    if (!is) return is;
    if (ch1 != '(' || ch2 != ',' || ch3 != ')') {
        is.clear(ios_base::failbit);
        return is;
    }
    p = Point{x,y};
    return is;
}

int main() {
    // insert code here...
    
    Point p0 {2, 3};
    cout << p0.x_value() << ", " << p0.y_value() << endl;
    cout << endl;
    
    // The Drill - 02
    cout << "Please enter 'x' and 'y'" << endl;
    vector<Point> original_points;
    for (int i=0; i<7; ++i) {
        Point p;
        cin >> p;
        original_points.push_back(p);
    }
    
    cout << endl;
    
    // The Drill - 04
    for (int i=0; i<original_points.size(); ++i) {
        cout << original_points[i] << endl;
    }
    
    cout << endl;
    
    // The Drill - 04
    ofstream ost;
    ost.open("mydata.txt",ios_base::in);
    cout << sizeof(ost) << endl;
    for (int i=0; i<original_points.size(); ++i) {
        ost << original_points[i];
    }
    ost.close();
    cout << sizeof(ost) << endl;
    
    cout << endl;
    
    // The Drill - 05
    ifstream ist;
    ist.open("mydata.txt",ios_base::out);
    vector<Point> processed_points;
    for (int i=0; i<original_points.size(); ++i) {
        Point p;
        ist >> p;
        processed_points.push_back(p);
    }
    ist.close();
    
    // The Drill - 06
    cout << "Original vector" << endl;
    for (int i=0; i<original_points.size(); ++i) {
        cout << original_points[i] << endl;
    }
    
    cout << "Processed vector" << endl;
    for (int i=0; i<processed_points.size(); ++i) {
        cout << processed_points[i] << endl;
    }
    
    // The Drill - 07
    if (original_points.size() == processed_points.size()) {
        cout << "The two vectors have the same number of elements." << endl;
    }
    else {
        cout << "Something's wrong!" << endl;
    }
    
    for (int i=0; i<original_points.size(); ++i) {
        if (original_points[i].x_value() == processed_points[i].x_value() && original_points[i].y_value() == processed_points[i].y_value()) {
            cout << "The points of the element " << i << " of the two vectors are the same." << endl;
        }
        else {
            cout << "Something's wrong!" << endl;
        }
    }
    
    return 0;
}
