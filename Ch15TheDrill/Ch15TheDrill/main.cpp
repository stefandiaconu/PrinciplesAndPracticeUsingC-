//
//  main.cpp
//  Ch15TheDrill
//
//  Created by Stefan Diaconu on 03/08/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include "../../Simple_window.h"

double one(double){ return 1; };
double slope(double x){ return x/2; };
double square(double x){ return x*x; };
double sloping_cos(double x){ return cos(x) + slope(x); };

int main(int argc, const char * argv[]) {
    // insert code here...
    Point tl{100,100};
    Simple_window win{tl,600,600,"Function graphs"};

    Axis x{Axis::x,Point{100,300},400,20,"1 == 20"};
    Axis y{Axis::y,Point{300,500},400,20,"1 == 20"};
    x.set_color(Color::red);
    y.set_color(Color::red);
    win.attach(x);
    win.attach(y);

    win.wait_for_button();

    Function s{one,-10,11,Point{300,300},400,400/20,400/20};
    win.attach(s);
    Function s2{slope,-10,11,Point{300,300},400,400/20,400/20};
    win.attach(s2);
    Function s3{square,-10,11,Point{300,300},400,400/20,400/20};
    win.attach(s3);
    Function s4{cos,-10,11,Point{300,300},400,400/20,400/20};
    s4.set_color(Color::blue);
    win.attach(s4);
    Function s5{sloping_cos,-10,11,Point{300,300},400,400/20,400/20};
    win.attach(s5);

    win.wait_for_button();
    
    return 0;
}
