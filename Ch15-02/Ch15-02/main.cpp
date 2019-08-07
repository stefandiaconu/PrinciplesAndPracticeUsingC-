//
//  main.cpp
//  Ch15-02
//
//  Created by Stefan Diaconu on 05/08/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#include <iostream>
#include "../../Simple_window.h"

double one(double){ return 1; };
double slope(double x){ return x/2; };
double square(double x){ return x*x; };
double sloping_cos(double x){ return cos(x) + slope(x); };
double sum_sin_cos(double x){ return sin(x) + cos(x); };

double leibniz(double n)
{
    double sum = 0;
    int denom = 1;
    int sign = 1;
    for (int i = 1; i <= n; i++)
    {
        sum += sign * 4.0 / denom;
        denom += 2;
        sign *= -1;
    }
    return sum;
};

int fac(int n) { return n>1 ? n*fac(n-1) : 1; };
double term(double x, int n) { return pow(x, n)/fac(n); };
double expe(double x, int n)
{
    double sum = 0;
    for (int i=0; i<n; ++i) sum += term(x,i);
    return sum;
};

//int expN_number_of_terms = 10;
//
//double expN(double x)
//{
//    return expe(x, expN_number_of_terms);
//}

class Func : public Shape {
    // the function parameters are not stored
public:
    Func(Fct f, double rr1, double rr2, Point orig, int ccount = 100, double xxscale = 25, double yyscale = 25)
        : f(f), p(orig), r_min(rr1), r_max(rr2), c_count(ccount), x_scale(xxscale), y_scale(yyscale)
    {
        if (r_max-r_min<=0) error("bad graphing range");
        if (ccount <=0) error("non-positive graphing count");
        double dist = (r_max-r_min)/ccount;
        double r = r_min;
        for (int i = 0; i<ccount; ++i) {
            add(Point(orig.x+int(r*xxscale),orig.y-int(f(r)*yyscale)));
            //cout << orig.x+int(r*x_scale) << ',' << orig.y-int(f(r)*y_scale) << endl;
            r += dist;
        }
    };
    
    double r1() { return r_min; };
    double r2() { return r_max; };
    Point xy() { return p; };
    int count() { return c_count; };
    double xscale() { return x_scale; };
    double yscale() { return y_scale; };
    
    void reset(Fct f, Func& ff, double r1, double r2);
    
private:
    Fct f;
    double r_min;
    double r_max;
    Point p;
    int c_count;
    double x_scale;
    double y_scale;
};

void Func::reset(Fct f, Func& ff, double rr1, double rr2)
{
    ff.r_min = rr1;
    ff.r_max = rr2;
    if (ff.r_max-ff.r_min<=0) error("bad graphing range");
    if (ff.c_count <=0) error("non-positive graphing count");
    double dist = (ff.r_max-ff.r_min)/ff.c_count;
    double r = ff.r_min;
    for (int i = 0; i<ff.c_count; ++i) {
        add(Point(ff.p.x+int(r*ff.x_scale),ff.p.y-int(f(r)*ff.y_scale)));
        cout << ff.p.x+int(r*ff.x_scale) << ',' << ff.p.y-int(ff.f(r)*ff.y_scale) << endl;
        r += dist;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Point tl{100,100};
    Simple_window win{tl,600,600,"Function graphs"};
    
    
    Axis x{Axis::x,Point{100,300},400,20,"1 == 20"};
    Axis y{Axis::y,Point{300,500},400,20,"1 == 20"};
    x.set_color(Color::red);
    y.set_color(Color::red);
    win.attach(x);
    win.attach(y);
    
    win.wait_for_button();
    
//    Func s{one,-10,11,Point{300,300},400,400/20,400/20};
//    win.attach(s);
//    Func s2{slope,-10,11,Point{300,300},400,400/20,400/20};
//    win.attach(s2);
//    Func s3{square,-10,11,Point{300,300},400,400/20,400/20};
//    win.attach(s3);
//    Func s4{cos,-10,11,Point{300,300},400,400/20,400/20};
//    s4.set_color(Color::blue);
//    win.attach(s4);
//    Func s5{sloping_cos,2,8,Point{300,300},400,400/20,400/20};
//    win.attach(s5);
//
//    win.wait_for_button();
    
//    Func s6{sloping_cos,-10,11,Point{300,300},400,400/20,400/20};
//    s6.reset(sloping_cos, s6, 2, 8);
//    s6.set_color(Color::red);
//    win.attach(s6);
//    win.wait_for_button();
    
//    Function s7{sum_sin_cos,-10,11,Point{300,300},400,400/20,400/20};
//    win.attach(s7);
//    win.wait_for_button();
    
    for (int n=1; n<20; ++n) {
        ostringstream ss;
        ss << "n == " << n;
        win.set_label(ss.str());
        //expN_number_of_terms = n;
        Function e{[n](double x){ return expe(x, n); },-10,11,Point{300,300},400,400/20,400/20};
        win.attach(e);
        win.wait_for_button();
        win.detach(e);
    }
    
    return 0;
}
