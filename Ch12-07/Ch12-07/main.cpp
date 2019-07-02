//
//  main.cpp
//  Ch12-07
//
//  Created by Stefan Diaconu on 02/07/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include "../../Simple_window.h"
#include "../../Graph.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    // Set the window
    Point tl{100,100};
    Simple_window win{tl,700,400,"My Window"};
    
    //************ Exercise 07 ***************//
    // Base
    Rectangle base{Point{100,200},100,150};
    // Roof
    Polygon roof;
    roof.add(Point{100,200});
    roof.add(Point{200,200});
    roof.add(Point{150,100});
    // Door
    Rectangle door{Point{130,300},40,50};
    
    // Windows
    Rectangle win1{Point{100,250},30,30};
    Rectangle win2{Point{170,250},30,30};
    
    // Chimney
    Rectangle chimney{Point{160,100},20,80};
    
    win.attach(base);
    win.attach(roof);
    win.attach(door);
    win.attach(win1);
    win.attach(win2);
    win.attach(chimney);
    win.wait_for_button();
    
    //************ Exercise 08 ***************//
    Circle c1{Point{300,100},50};
    c1.set_color(Color::blue);
    Circle c2{Point{420,100},50};
    c2.set_color(Color::black);
    Circle c3{Point{540,100},50};
    c3.set_color(Color::red);
    Circle c4{Point{360,150},50};
    c4.set_color(Color::yellow);
    Circle c5{Point{480,150},50};
    c5.set_color(Color::green);
    win.attach(c1);
    win.attach(c2);
    win.attach(c3);
    win.attach(c4);
    win.attach(c5);
    win.wait_for_button();
    
    //************ Exercise 09 ***************//
    Image i{Point{300,200},"imagee.jpg"};
    win.attach(i);
    
    win.wait_for_button();
    
    return 0;
}
