//
//  main.cpp
//  Ch16-01
//
//  Created by Stefan Diaconu on 10/08/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include "../../Window.h"
#include "../../GUI.h"
#include "../../Graph.h"
using namespace Graph_lib;

struct My_window : Window {
    Point origin{0,0};
    
    My_window(Point xy, int w, int h, const string& title ):
    Window(xy,w,h,title),
    next_button(Point(x_max()-150,0), 70, 20, "Next", cb_next),
    quit_button(Point{x_max()-70,0},70,20,"Quit",cb_quit),
    square_buttons(origin,50,50,Menu::vertical,"square"),
    out(Point{x_max()-120,30},100,20,"button(top-left) (x,y):"),
    button_pushed(false)
    {
        attach(next_button);
        attach(quit_button);
        attach(out);
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                square_buttons.attach(new Button{Point{i*50,j*50},0,0,"button",cb_button});
            }
            attach(square_buttons);
            square_buttons.loc.x += 50;
            square_buttons.offset = 0;
        }
    }
    
    bool wait_for_button(); // simple event loop
    
private:
    Button next_button;     // the "next" button
    Button quit_button;
    Menu square_buttons;
    Out_box out;
    bool button_pushed;     // implementation detail
    
    static void cb_next(Address, Address); // callback for next_button
    static void cb_quit(Address, Address);
    static void cb_button(Address, Address);
    void next();            // action to be done when next_button is pressed
    void quit();
    void button();
    
};

void My_window::next()
{
    button_pushed = true;
}

void My_window::quit()
{
    hide();
}

void My_window::cb_next(Address, Address pw)
// call Simple_window::next() for the window located at pw
{
    reference_to<My_window>(pw).next();
}

void My_window::cb_quit(Address, Address pw)
// call Simple_window::next() for the window located at pw
{
    reference_to<My_window>(pw).quit();
}

bool My_window::wait_for_button()
// modified event loop:
// handle all events (as per default), quit when button_pushed becomes true
// this allows graphics without control inversion
{
    show();
    button_pushed = false;
#if 1
    // Simpler handler
    while (!button_pushed) Fl::wait();
    Fl::redraw();
#else
    // To handle the case where the user presses the X button in the window frame
    // to kill the application, change the condition to 0 to enable this branch.
    Fl::run();
#endif
    return button_pushed;
}

void My_window::button()
{
    ostringstream ss;
    for (int i=0; i<square_buttons.selection.size(); ++i) {
        if (square_buttons.selection[i].pressed()){
            ss << '(' << square_buttons.selection[i].loc.x << ',' << square_buttons.selection[i].loc.y << ')';}
        out.put(ss.str());
    }
    
    redraw();
}

void My_window::cb_button(Address, Address pw)
{
    reference_to<My_window>(pw).button();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    My_window win{Point{100,100},600,600,"My Window"};
    
    return gui_main();
}
