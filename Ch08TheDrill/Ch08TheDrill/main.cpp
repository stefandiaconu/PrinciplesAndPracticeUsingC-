//
//  main.cpp
//  Ch08TheDrill
//
//  Created by Stefan Diaconu on 23/04/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include "my.h"
#include <iostream>

int foo = 7; // Exercise 1

// Exercise 2
//void swap_v(int a, int b)
//{
//    int temp;
//    temp = a;
//    a = b;
//    b = temp;
//}
//
//void swap_r(int& a, int& b)
//{
//    int temp;
//    temp = a;
//    a = b;
//    b = temp;
//}
//
//void swap_cr(const int& a, const int& b)
//{
//    int temp;
//    temp = a;
//}

// Exercise 3
namespace X {
    int var;
    void print(){ std::cout << var << std::endl; };
}

namespace Y {
    int var;
    void print(){ std::cout << var << std::endl; };
}

namespace Z {
    int var;
    void print(){ std::cout << var << std::endl; };
}

int main()
{
    // Exercise 1
    //print_foo();
    //print(99);
    
    //Exercise 2
//    int x = 7;
//    int y = 9;
//    swap_v(x, y);
//    std::cout << x << " " << y << std::endl;
//    swap_r(x, y);
//    std::cout << x << " " << y << std::endl;
//    swap_cr(x, y);
//    std::cout << x << " " << y << std::endl;
//    swap_v(7, 9);
//    //swap_r(7, 9);
//    swap_cr(7, 9);
//    const int cx = 7;
//    const int cy = 9;
//    swap_v(cx, cy);
//    std::cout << cx << " " << cy << std::endl;
//    //swap_r(cx, cy);
//    swap_cr(cx, cy);
//    std::cout << cx << " " << cy << std::endl;
//    swap_v(7.7, 9.9);
//    //swap_r(7.7, 9.9);
//    swap_cr(7.7, 9.9);
//    double dx = 7.7;
//    double dy = 9.9;
//    swap_v(dx, dy);
//    std::cout << dx << " " << dy << std::endl;
//    //swap_r(dx, dy);
//    swap_cr(dx, dy);
//    std::cout << dx << " " << dy << std::endl;
//    swap_v(7.7, 9.9);
//    //swap_r(7.7, 9.9);
//    swap_cr(7.7, 9.9);
    
    //Exercise 3
    X::var = 7;
    X::print();
    using namespace Y;
    var = 9;
    print();
    {
        using Z::var;
        using Z::print;
        var = 11;
        print();
    }
    print();
    X::print();
    
    return 0;
}
