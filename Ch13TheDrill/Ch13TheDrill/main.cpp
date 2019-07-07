//
//  main.cpp
//  Ch13TheDrill
//
//  Created by Stefan Diaconu on 05/07/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include "../../Simple_window.h"
#include "../../Graph.h"
#include <random>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // Create window
    Point tl{100,100};
    Simple_window win{tl,1000,800,"My Window"};
    
    // Create grid
    int x_grid = 100;
    int y_grid = 100;
    Lines grid;
    for (int i=x_grid; i<=800; i+=x_grid) {
        grid.add(Point{i,0}, Point{i,800});
    }

    for (int j=y_grid; j<=800; j+=y_grid) {
        grid.add(Point{0,j}, Point{800,j});
    }
    win.attach(grid);
    
    Vector_ref<Rectangle> recs;
    for (int i=0; i<=800; i+=100) {
        for (int j=0; j<=800; j+=100) {
            recs.push_back(new Rectangle{Point{i,j},x_grid,y_grid});
            recs[recs.size()-1].set_fill_color(Color::red);
            win.attach(recs[recs.size()-1]);
            i+=x_grid;
        }
    }
    win.wait_for_button();
    
    // Create image
    Image i1{Point{200,0},"seal.jpg"};
    win.attach(i1);
    Image i2{Point{0,200},"seal.jpg"};
    win.attach(i2);
    Image i3{Point{400,600},"seal.jpg"};
    win.attach(i3);
    
    // Move image from square to square
    Image i4{Point{x_grid,y_grid},"smile.jpg"};
    win.attach(i4);
    int x = 0;
    int y = 0;
    int dx = 0;
    int dy = 0;
    while (true) {
        x = rand() % 8;
        y = rand() % 8;
        dx = 100*x - i4.point(0).x;
        dy = 100*y - i4.point(0).y;
        i4.move(dx,dy);
        //win.resize(1000,800);
        win.wait_for_button();
    }
    
    return 0;
}
