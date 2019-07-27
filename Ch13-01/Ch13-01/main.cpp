//
//  main.cpp
//  Ch13-01
//
//  Created by Stefan Diaconu on 07/07/2019.
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
     **************************************** Ch13-01 **********************************************
     ***********************************************************************************************/
    Arc a{Point{50,50},50,45,225};
    win.attach(a);
    win.wait_for_button();
    
    /***********************************************************************************************
     **************************************** Ch13-02 **********************************************
     ***********************************************************************************************/
    Box b{Point{50,100},30,300,100};
    win.attach(b);
    
    /***********************************************************************************************
     **************************************** Ch13-03 **********************************************
     ***********************************************************************************************/
    Arrow arrow(Point(200, 250), Point(300, 100), false, true, 10);
    arrow.set_color(Color::red);
    
    win.attach(arrow);
    win.wait_for_button();
    
    /***********************************************************************************************
     **************************************** Ch13-04 **********************************************
     ***********************************************************************************************/
    Rectangle rect{Point{50,250},200,100};
    rect.set_color(Color::dark_green);
    
    Point p1 = sw(rect);
    Mark m1{p1,'x'};
    m1.set_color(Color::red);
    
    win.attach(rect);
    win.attach(m1);
    
    win.wait_for_button();
    
    /***********************************************************************************************
     **************************************** Ch13-05 **********************************************
     ***********************************************************************************************/
    Circle c{Point{150,450},100};
    Point p2 = nw_circle(c);
    Mark m2{p2,'x'};
    m2.set_color(Color::red);
    win.attach(c);
    win.attach(m2);
    win.wait_for_button();
    
    Ellipse e{Point{150,700},100,50};
    Point p3 = nw_ellipse(e);
    Mark m3{p3,'x'};
    m3.set_color(Color::red);
    win.attach(e);
    win.attach(m3);
    win.wait_for_button();
    
    /***********************************************************************************************
     **************************************** Ch13-06 **********************************************
     ***********************************************************************************************/
    Box window{Point{400,100},10,150,30};
    Text t1(Point{450,120}, "Window");
    win.attach(window);
    win.attach(t1);
    Box line_style{Point{570,100},10,130,30};
    Text t2(Point{600,120}, "Line_style");
    win.attach(line_style);
    win.attach(t2);
    Box color{Point{720,100},10,100,30};
    Text t3(Point{750,120}, "Color");
    win.attach(color);
    win.attach(t3);
    Box simple_window{Point{350,200},10,200,30};
    Text t4(Point{370,220}, "Simple_window");
    win.attach(simple_window);
    win.attach(t4);
    Box shape{Point{600,180},10,100,30};
    Text t5(Point{620,200}, "Shape");
    win.attach(shape);
    win.attach(t5);
    Box point{Point{750,200},10,100,30};
    Text t6(Point{770,220}, "Point");
    win.attach(point);
    win.attach(t6);
    Box line{Point{300,350},10,80,30};
    Text t7(Point{320,370}, "Line");
    win.attach(line);
    win.attach(t7);
    Box lines{Point{400,350},10,80,30};
    Text t8(Point{420,370}, "Lines");
    win.attach(lines);
    win.attach(t8);
    Box polygon{Point{500,350},10,80,30};
    Text t9(Point{520,370}, "Polygon");
    win.attach(polygon);
    win.attach(t9);
    Box axis{Point{600,350},10,60,30};
    Text t10(Point{620,370}, "Axis");
    win.attach(axis);
    win.attach(t10);
    Box rectangle{Point{680,350},10,100,30};
    Text t11(Point{700,370}, "Rectangle");
    win.attach(rectangle);
    win.attach(t11);
    Box text{Point{800,350},10,60,30};
    Text t12(Point{820,370}, "Text");
    win.attach(text);
    win.attach(t12);
    Box image{Point{880,350},10,80,30};
    Text t13(Point{900,370}, "Image");
    win.attach(image);
    win.attach(t13);
    
    Arrow a1(Point(450, 200), Point(475, 130), false, true, 5);
    Arrow a2(Point(340, 350), Point(620, 210), false, true, 5);
    Arrow a3(Point(440, 350), Point(630, 210), false, true, 5);
    Arrow a4(Point(540, 350), Point(640, 210), false, true, 5);
    Arrow a5(Point(630, 350), Point(650, 210), false, true, 5);
    Arrow a6(Point(730, 350), Point(660, 210), false, true, 5);
    Arrow a7(Point(830, 350), Point(670, 210), false, true, 5);
    Arrow a8(Point(920, 350), Point(680, 210), false, true, 5);
    win.attach(a1);
    win.attach(a2);
    win.attach(a3);
    win.attach(a4);
    win.attach(a5);
    win.attach(a6);
    win.attach(a7);
    win.attach(a8);
    
    win.wait_for_button();
    
    /***********************************************************************************************
     **************************************** Ch13-07 **********************************************
     ***********************************************************************************************/
    int cell_size = 20;
    Vector_ref<Rectangle> recs;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            for (int k = 0; k < 6; ++k) {
                recs.push_back(new Graph_lib::Rectangle(Point(i * 6 * cell_size + j*cell_size, k*cell_size), cell_size, cell_size));
                recs[recs.size() - 1].set_fill_color(fl_rgb_color(51 * i, 51 * j, 51 * k));
                recs[recs.size() - 1].set_color(Color(Color::black, Color::invisible));
                win.attach(recs[recs.size() - 1]);
            }
        }
    }

    win.wait_for_button();
    
    /***********************************************************************************************
     **************************************** Ch13-08 **********************************************
     ***********************************************************************************************/
    Regular_hexagon hexagon{Point{300,500},50};
    win.attach(hexagon);
    
    win.wait_for_button();
    
    /***********************************************************************************************
     **************************************** Ch13-09 **********************************************
     ***********************************************************************************************/
    int r = 50;
    int add_x = r * 3;
    int add_y = (sin(M_PI / 3) * r);
    Vector_ref<Regular_hexagon> hexs;
    for (int i=0; i<5; ++i) {
        for(int j=0; j<5; ++j) {
            if (j % 2 == 0 || j == 0){
                hexs.push_back(new Regular_hexagon{Point{i * add_x, j * add_y},r});
                win.attach(hexs[hexs.size()-1]);
            }
            else {
                hexs.push_back(new Regular_hexagon{Point{i * add_x + (r + r / 2), j * add_y},r});
                win.attach(hexs[hexs.size()-1]);
            }
        }
    }
    win.wait_for_button();
    
    return 0;
}
