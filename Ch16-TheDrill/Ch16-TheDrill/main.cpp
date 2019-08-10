//
//  main.cpp
//  Ch16-TheDrill
//
//  Created by Stefan Diaconu on 09/08/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include "../../Window.h"
#include "../../GUI.h"
#include "../../Graph.h"

using namespace Graph_lib;

struct Lines_window : Window {
    Lines_window(Point xy, int w, int h, const string& title);
    
private:
    Open_polyline lines;
    
    Button next_button;
    Button quit_button;
    
    In_box next_x;
    In_box next_y;
    Out_box xy_out;
    
    Menu color_menu;
    Button menu_button;
    Menu style_menu;
    Button menu_style_button;
    
    void change(Color c) { lines.set_color(c); }
    void change_line_style(Line_style  l) {lines.set_style(l); }
    
    void hide_menu() { color_menu.hide(); menu_button.show(); }
    void hide_style_menu() { style_menu.hide(); menu_style_button.show(); }
    
    void red_pressed() { change(Color::red); hide_menu(); }
    void blue_pressed() { change(Color::blue); hide_menu(); }
    void black_pressed() { change(Color::black); hide_menu(); }
    void menu_pressed() { menu_button.hide(); color_menu.show(); }
    void solid_pressed() { change_line_style(Line_style::solid); hide_style_menu(); }
    void dash_pressed() { change_line_style(Line_style::dash); hide_style_menu(); }
    void dot_pressed() { change_line_style(Line_style::dot); hide_style_menu(); }
    void dashdot_pressed() { change_line_style(Line_style::dashdot); hide_style_menu(); }
    void dashdotdot_pressed() { change_line_style(Line_style::dashdotdot); hide_style_menu(); }
    void menu_style_pressed() { menu_style_button.hide(); style_menu.show(); }
    void next();
    void quit();
    
    static void cb_red(Address, Address);
    static void cb_blue(Address, Address);
    static void cb_black(Address, Address);
    static void cb_menu(Address, Address);
    static void cb_next(Address, Address);
    static void cb_quit(Address, Address);
    static void cb_solid(Address, Address);
    static void cb_dash(Address, Address);
    static void cb_dot(Address, Address);
    static void cb_dashdot(Address, Address);
    static void cb_dashdotdot(Address, Address);
    static void cb_menu_style(Address, Address);
    
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
:Window{xy,w,h,title},
next_button{Point{x_max()-150,0},70,20,"Next point",cb_next},
quit_button{Point{x_max()-70,0},70,20,"Quit button",cb_quit},
next_x{Point{x_max()-310,0},50,20,"next x"},
next_y{Point{x_max()-210,0},50,20,"next y"},
xy_out{Point{100,0},100,20,"currrent (x,y):"},
color_menu{Point{x_max()-70,30},70,20,Menu::vertical,"color"},
menu_button{Point{x_max()-80,30},80,20,"color menu",cb_menu},
style_menu{Point{x_max()-70,100},70,20,Menu::vertical,"style"},
menu_style_button{Point{x_max()-80,100},80,20,"style menu",cb_menu_style}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point");
    color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
    color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
    color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});
    attach(color_menu);
    color_menu.hide();
    attach(menu_button);
    style_menu.attach(new Button{Point{0,0},0,0,"solid",cb_solid});
    style_menu.attach(new Button{Point{0,0},0,0,"-----",cb_dash});
    style_menu.attach(new Button{Point{0,0},0,0,".....",cb_dot});
    style_menu.attach(new Button{Point{0,0},0,0,"-.-.-.",cb_dashdot});
    style_menu.attach(new Button{Point{0,0},0,0,"-..-..",cb_dashdotdot});
    attach(style_menu);
    style_menu.hide();
    attach(menu_style_button);
    attach(lines);
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();
    lines.add(Point{x,y});
    
    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());
    
    redraw();
}

void Lines_window::cb_red(Address, Address pw) { reference_to<Lines_window>(pw).red_pressed(); }
void Lines_window::cb_blue(Address, Address pw) { reference_to<Lines_window>(pw).blue_pressed(); }
void Lines_window::cb_black(Address, Address pw) { reference_to<Lines_window>(pw).black_pressed(); }
void Lines_window::cb_menu(Address, Address pw) { reference_to<Lines_window>(pw).menu_pressed(); }
void Lines_window::cb_next(Address, Address pw) { reference_to<Lines_window>(pw).next(); }
void Lines_window::cb_quit(Address, Address pw) { reference_to<Lines_window>(pw).quit(); }
void Lines_window::cb_solid(Address, Address pw) { reference_to<Lines_window>(pw).solid_pressed(); }
void Lines_window::cb_dash(Address, Address pw) { reference_to<Lines_window>(pw).dash_pressed(); }
void Lines_window::cb_dot(Address, Address pw) { reference_to<Lines_window>(pw).dot_pressed(); }
void Lines_window::cb_dashdot(Address, Address pw) { reference_to<Lines_window>(pw).dashdot_pressed(); }
void Lines_window::cb_dashdotdot(Address, Address pw) { reference_to<Lines_window>(pw).dashdotdot_pressed(); }
void Lines_window::cb_menu_style(Address, Address pw) { reference_to<Lines_window>(pw).menu_style_pressed(); }

int main(int argc, const char * argv[]) {
    // insert code here...
    Lines_window win{Point{100,100},600,600,"lines"};
    
    return gui_main();
    
    return 0;
}
