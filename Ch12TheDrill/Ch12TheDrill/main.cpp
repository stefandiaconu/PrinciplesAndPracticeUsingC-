//
//  main.cpp
//  Ch12TheDrill
//
//  Created by Stefan Diaconu on 25/06/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "../../Simple_window.h"
#include "../../Graph.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    try {
        using namespace Graph_lib;
        
        Point tl{100,100};
        Simple_window win{tl,600,400,"My Window"};
        
        Axis xa{Axis::x,Point{20,300},280,10,"x axis"};     // make an Axis
                // an Axis is a kind of Shape
                // Axis::x means horizontal
                // starting at (20,300)
                // 280 pixel long
                // 10 "notches"
                // label the axis "x axis"
        win.attach(xa);                                     // attach 'xa' to the window, 'win'
        win.set_label("My Window #2");                      // relabel the window
        win.wait_for_button();
        
        Axis ya{Axis::y,Point{20,300},280,10,"y axis"};
        ya.set_color(Color::cyan);                          // choose a color
        ya.label.set_color(Color::dark_red);                // choose a color for the text
        win.attach(ya);
        win.set_label("My Window #3");
        win.wait_for_button();
        
        Function sine {sin,0,100,Point{20,150},1000,50,50};     // sine curve
                // plot 'sin' in the range [0:100] with (0,0) at (20,150)
                // using 1000 points, scale x values *50, scale y values *50
        win.attach(sine);
        win.set_label("My Window #4");
        win.wait_for_button();
        
        sine.set_color(Color::blue);
        
        Polygon poly;
        poly.add(Point{300,200});
        poly.add(Point{350,100});
        poly.add(Point{400,200});
        
        poly.set_color(Color::red);
        poly.set_style(Line_style::dash);
        win.attach(poly);
        win.set_label("My Window #5");
        win.wait_for_button();
        
        Rectangle r {Point{200,200},100,50};                // top left corner, width, height
        win.attach(r);
        win.set_label("My Window #6");
        win.wait_for_button();
        
        Closed_polyline poly_rect;
        poly_rect.add(Point{100,50});
        poly_rect.add(Point{200,50});
        poly_rect.add(Point{200,100});
        poly_rect.add(Point{100,100});
        win.attach(poly_rect);
        
        poly_rect.add(Point{50,75});
        
        r.set_fill_color(Color::yellow);                    // color the inside of the rectangle
        poly.set_style(Line_style(Line_style::dash,4));
        poly_rect.set_style(Line_style(Line_style::dash,2));
        poly_rect.set_fill_color(Color::green);
        win.set_label("My Window #7");
        win.wait_for_button();
        
        Text t {Point{150,150},"Hello, graphical world!"};
        win.attach(t);
        win.set_label("My Window #8");
        win.wait_for_button();
        
        t.set_font(Font::times_bold);
        t.set_font_size(20);
        win.set_label("My Window #9");
        win.wait_for_button();
        
        Image ii {Point{100,50},"image.jpg"};
        win.attach(ii);
        win.set_label("My Window #10");
        win.wait_for_button();
        
        ii.move(100,200);
        win.set_label("My Window #11");
        win.wait_for_button();
        
        Circle c {Point{100,200},50};
        Ellipse e {Point{100,200},75,25};
        e.set_color(Color::dark_red);
        Mark m {Point{100,200},'x'};
        
        ostringstream oss;
        oss << "Screen size: " << x_max() << "*" << y_max()
            <<  "; window size: " << win.x_max() << "*" << win.y_max();
        Text sizes {Point{100,20},oss.str()};
        
        Image cal {Point{225,225},"snow.gif"};
        cal.set_mask(Point{40,40}, 200, 150);
        
        win.attach(c);
        win.attach(m);
        win.attach(e);
        
        win.attach(sizes);
        win.attach(cal);
        win.set_label("My Window #12");
        win.wait_for_button();
        
    } catch (exception e) {
        cerr << "Exception: " << e.what() << endl;
    } catch (...) {
        cerr << "Exception" << endl;
    }

    
    return 0;
}
