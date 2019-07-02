//
//  main.cpp
//  Ch12-01
//
//  Created by Stefan Diaconu on 01/07/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include "../../Simple_window.h"
#include "../../Graph.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    using namespace Graph_lib;
    
    // Set window
    Point tl{100,100};
    Simple_window win{tl,600,400,"Ch12-01"};
    
    //************ Exercise 01 ***************//
    // Create a rectangle using 'Rectangle'
    Rectangle rect{Point{30,30},200,100};
    rect.set_color(Color::blue);
    win.attach(rect);
    
    // Create a rectangle using 'Polygon'
    Polygon rect_poly;
    rect_poly.add(Point{50,150});
    rect_poly.add(Point{50,200});
    rect_poly.add(Point{250,200});
    rect_poly.add(Point{250,150});
    rect_poly.set_color(Color::red);
    win.attach(rect_poly);
    
    //************ Exercise 02 ***************//
    Rectangle rect2{Point{300,10},100,30};
    Text t{Point{330,30},"Howdy!"};
    win.attach(rect2);
    win.attach(t);
    
    //************ Exercise 03 ***************//
    Text t2{Point{10,390},"S"};
    t2.set_font_size(150);
    t2.set_color(Color::red);
    Text t3{Point{110,390},"D"};
    t3.set_font_size(150);
    t3.set_color(Color::white);
    win.attach(t2);
    win.attach(t3);
    win.wait_for_button();
    
    //************ Exercise 04 ***************//
    Rectangle r1{Point{300,300},30,30};
    Rectangle r2{Point{330,300},30,30};
    Rectangle r3{Point{360,300},30,30};
    Rectangle r4{Point{330,330},30,30};
    Rectangle r5{Point{330,330},30,30};
    Rectangle r6{Point{360,330},30,30};
    Rectangle r7{Point{300,360},30,30};
    Rectangle r8{Point{330,360},30,30};
    Rectangle r9{Point{360,360},30,30};
    r1.set_fill_color(Color::red);
    r2.set_fill_color(Color::white);
    r3.set_fill_color(Color::red);
    r4.set_fill_color(Color::white);
    r5.set_fill_color(Color::red);
    r6.set_fill_color(Color::white);
    r7.set_fill_color(Color::red);
    r8.set_fill_color(Color::white);
    r9.set_fill_color(Color::red);
    win.attach(r1);
    win.attach(r2);
    win.attach(r3);
    win.attach(r4);
    win.attach(r5);
    win.attach(r6);
    win.attach(r7);
    win.attach(r8);
    win.attach(r9);
    win.wait_for_button();
    
    //************ Exercise 05 ***************//
    int width = win.x_max() * 0.67;
    int height = win.y_max() * 0.75;
    Rectangle rec3{Point{50,50},width,height};
    rec3.set_style(Line_style(Line_style::solid,2));
    rec3.set_color(Color::red);
    win.attach(rec3);
    
    //************ Exercise 06 ***************//
    Rectangle rec4{Point{500,300},300,50};
    win.attach(rec4);
    
    win.wait_for_button();
    
    
    return 0;
}
