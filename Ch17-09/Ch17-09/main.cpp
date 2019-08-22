//
//  main.cpp
//  Ch17-09
//
//  Created by Stefan Diaconu on 22/08/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // determine stack growth direction
    int i1 = 0;
    int i2 = 0;
    int i3 = 0;
    std::cout << "Addresses on stack:\n" << &i1 << "\n" << &i2 << "\n" << &i3 << std::endl;
    int stack_diff = &i2 - &i1;
    std::cout << stack_diff << std::endl;
    if (stack_diff > 0) std::cout << "Stack grows up" << std::endl;
    else std::cout << "Stack grows down" << std::endl;
    
    // determine heap growth direction
    int* ip1 = new int(0);
    int* ip2 = new int(0);
    int* ip3 = new int(0);
    std::cout << "Addresses on heap\n" << ip1 << "\n" << ip2 << "\n" << ip3 << std::endl;
    int heap_diff = ip2 - ip1;
    std::cout << heap_diff << std::endl;
    if (heap_diff > 0) std::cout << "Heap grows up" << std::endl;
    else std::cout << "Heap grows down" << std::endl;
    
    return 0;
}
