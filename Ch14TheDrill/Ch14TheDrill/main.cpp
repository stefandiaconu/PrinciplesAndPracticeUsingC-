//
//  main.cpp
//  Ch14TheDrill
//
//  Created by Stefan Diaconu on 28/07/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>

//-------------------- 1 ---------------------//
class B1
{
public:
    virtual void pvf() = 0;
    virtual void vf() const { std::cout << "B1::vf()" << std::endl; };
    void f() const { std::cout << "B1::f()" << std::endl; };
};

//-------------------- 2 ---------------------//
class D1 : public B1
{
public:
    void vf() const { std::cout << "D1::vf()" << std::endl; };
    void f() { std::cout << "D1::f()" << std::endl; };
};

class D2 : public D1
{
public:
    void pvf() override;
};

void D2::pvf() {};

class B2
{
public:
    virtual void pvf() = 0;
};

class D21 : public B2
{
public:
    std::string str = "Stefan";
    void pvf() override;
};

void D21::pvf() { std::cout << str << std::endl; };

class D22 : public B2
{
public:
    int n = 7;
    void pvf() override;
};

void D22::pvf() { std::cout << n << std::endl; };

void f(B2& b) { b.pvf(); };

//-------------------- 3 ---------------------//
void call(const B1& b)
{
    b.vf();
    b.f();
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    B1 b;
//    b.vf();
//    b.f();
//    b.pvf();
//    D1 d;
//    d.vf();
//    d.f();
//    d.pvf();
//    call(b);
//    call(d);
    
//    D2 d2;
//    d2.f();
//    d2.vf();
//    d2.pvf();
    
    D21 d21;
    f(d21);
    D22 d22;
    f(d22);
    
    return 0;
}
