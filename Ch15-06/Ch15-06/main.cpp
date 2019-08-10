//
//  main.cpp
//  Ch15-06
//
//  Created by Stefan Diaconu on 07/08/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include "../../Simple_window.h"

constexpr int xmax = 600;
constexpr int ymax = 600;

constexpr int x_orig = xmax / 2;
constexpr int y_orig = ymax / 2;
Point orig(x_orig, y_orig);

constexpr int r_min = -10;
constexpr int r_max = 10;

constexpr int n_points = 400;

constexpr int x_scale = 20;
constexpr int y_scale = 20;

constexpr int xoffset = 100;
constexpr int yoffset = 100;

constexpr int xspace = 100;
constexpr int yspace = 100;

constexpr int xlength = xmax - xoffset - xspace;
constexpr int ylength = ymax - yoffset - yspace;

class Bar_Graph : public Shape
{
public:
    Bar_Graph(vector<double> b_bar, Point orig, int bar_width, int bar_gap)
        : bar(b_bar), orig(orig), bar_width(bar_width), bar_gap(bar_gap)
    {};
    
    vector<double> bars() { return bar; };
    Point origin() { return orig; };
    int barWidth() { return bar_width; };
    int barGap() { return bar_gap; };
    
    void draw_lines() const;
private:
    vector<double> bar;
    Point orig;
    int bar_width;
    int bar_gap;
};

void Bar_Graph::draw_lines() const
{
    for (int i=0; i<bar.size(); ++i) {
        Point p1{orig.x + i * (bar_width + bar_gap), orig.y};
        Point p2{orig.x + i * (bar_width + bar_gap) + bar_width, orig.y};
        Point p3{orig.x + i * (bar_width + bar_gap) + bar_width, orig.y - (int)bar[i]};
        Point p4{orig.x + i * (bar_width + bar_gap), orig.y - (int)bar[i]};
        
        Closed_polyline cp;
        cp.add(p1);
        cp.add(p2);
        cp.add(p3);
        cp.add(p4);
        
        cp.set_color(Color::red);
        cp.set_fill_color(Color::red);
        
        cp.draw();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Point tl(100, 100);
    Simple_window win(tl, xmax, ymax, "Function graphs.");
    
    Axis x(Axis::x, Point(orig.x - 200, orig.y), 400, 20, "1 == 20");
    x.set_color(Color::black);
    win.attach(x);
    
    Axis y(Axis::y, Point(orig.x, orig.y + 200), 400, 20, "1 == 20");
    y.set_color(Color::black);
    win.attach(y);
    
    vector<double> d = { 120, 123, 115, 110, 55};
    
    Bar_Graph bg(d, orig, 10, 20);
    
    win.attach(bg);
    
    win.wait_for_button();
    
    return 0;
}
