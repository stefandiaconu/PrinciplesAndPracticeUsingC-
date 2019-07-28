//
//  main.cpp
//  Ch13-11
//
//  Created by Stefan Diaconu on 27/07/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include "Header.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    using namespace Graph_lib;
    
    Point tl{100,100};
    Simple_window win{tl,1024,800,"My Window"};
    
    /***********************************************************************************************
     **************************************** Ch13-11 **********************************************
     ***********************************************************************************************/
    int major = 150;
    int minor = 100;
    double c = sqrt(pow(major,2) - pow(minor, 2));
    Ellipse e{Point{200,400},major,minor};
    win.attach(e);
    
    Axis xa{Axis::x,Point{200,400},400,10,"x axis"};
    win.attach(xa);
    Axis ya{Axis::y,Point{200,400},300,10,"y axis"};
    win.attach(ya);
    
    Mark foci1{Point{(int)(200+c),400},'x'};
    Mark foci2{Point{(int)(200-c),400},'x'};
    win.attach(foci1);
    win.attach(foci2);
    
    Mark m1{Point{200+(int)(cos(M_PI / 3) * major),400 - (int)(sin(M_PI / 3) * minor)},'x'};
    win.attach(m1);
    
    Line line1{Point{(int)(200+c),400},Point{200+(int)(cos(M_PI / 3) * major),400 - (int)(sin(M_PI / 3) * minor)}};
    Line line2{Point{(int)(200-c),400},Point{200+(int)(cos(M_PI / 3) * major),400 - (int)(sin(M_PI / 3) * minor)}};
    win.attach(line1);
    win.attach(line2);
    
    win.wait_for_button();
    
    /***********************************************************************************************
     **************************************** Ch13-12 **********************************************
     ***********************************************************************************************/
    int r = 100;
    int x = 400;
    int y = 200;
    Circle c1{Point{x,y},r};
    win.attach(c1);
    double parameter = 0;
    for (int i=0; i<=360; i+=45){
        Mark myMark{ptOnCircle(c1, parameter),'x'};
        myMark.set_color(Color::red);
        win.attach(myMark);
        parameter += 0.1;
        win.wait_for_button();
    }
    
    win.wait_for_button();
    
    return 0;
}
