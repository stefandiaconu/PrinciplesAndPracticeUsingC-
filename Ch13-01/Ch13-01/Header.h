//
//  Header.h
//  Ch13-01
//
//  Created by Stefan Diaconu on 20/07/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include "../../Simple_window.h"
#include "../../Graph.h"
#include <cmath>

double pointVecMag(Point vec) {
    return sqrt(pow(vec.x, 2) + pow(vec.y, 2));;
}

/***********************************************************************************************
 **************************************** Ch13-01 **********************************************
 ***********************************************************************************************/
class Arc : public Shape {
    
public:
    Arc(Point xy, int rr, int st, int en) : p{xy}, r{rr}, start{st}, end{en}
    {
        add(xy);
    };
    void draw_lines() const;
    
    Point point() const { return p; };
    int r_r() const { return r; };
    int sta() const { return start; };
    int e() const { return end; };
    
private:
    Point p;
    int r;
    int start;
    int end;
};

void Arc::draw_lines() const
{
    using namespace Graph_lib;
    if (color().visibility()) {
        fl_arc(Shape::point(0).x, Shape::point(0).y, r+r, r+r, start, end);
    }
}

/***********************************************************************************************
 **************************************** Ch13-02 **********************************************
 ***********************************************************************************************/
class Box : public Shape
{
public:
    Box(Point xy, int rr, int w, int h) : o{xy}, r{rr}, width{w}, height{h}
    {
        a1 = Point(o.x + r, o.y);
        a2 = Point(o.x, o.y + r);
        b1 = Point(o.x + w - r, o.y);
        b2 = Point(o.x + w, o.y + r);
        c1 = Point(o.x + w, o.y + h - r);
        c2 = Point(o.x + w - r, o.y + h);
        d1 = Point(o.x + r, o.y + h);
        d2 = Point(o.x, o.y + h - r);
        
        a3 = Point(o.x + r, o.y + r);
        b3 = Point(o.x + w - r, o.y + r);
        c3 = Point(o.x + w - r, o.y + h - r);
        d3 = Point(o.x + r, o.y + h - r);
    };
    void draw_lines() const;
    
    Point point() const { return o; };
    int r_r() const { return r; };
    int w() const { return width; };
    int h() const { return height; };
    
private:
    Point o;
    Point a1, a2, b1, b2, c1, c2,d1 ,d2;
    Point a3, b3, c3, d3;
    int r;
    int width;
    int height;
};

void Box::draw_lines() const
{
    using namespace Graph_lib;
    fl_line(a1.x, a1.y, b1.x, b1.y);
    fl_line(b2.x, b2.y, c1.x, c1.y);
    fl_line(c2.x, c2.y, d1.x, d1.y);
    fl_line(d2.x, d2.y, a2.x, a2.y);
    
    fl_arc(o.x, o.y, r+r, r+r, 90, 180);
    fl_arc(o.x + width - (r+r), o.y, r+r, r+r, 360, 90);
    fl_arc(o.x + width - (r + r), o.y + height - (r + r), r+r, r+r, 270, 360);
    fl_arc(o.x, o.y + height - (r + r), r+r, r+r, 180, 270);
}

/***********************************************************************************************
 **************************************** Ch13-03 **********************************************
 ***********************************************************************************************/
class Arrow : public Shape
{
public:
    Arrow(Point start, Point end, bool s, bool e, int size)
    :start(start), end(end), s(s), e(e), size(size)
    {
        if (s) {
            //end-start vector: c
            c = Point(end.x - start.x, end.y - start.y);
            cMag = pointVecMag(c);
            cUnit = Point(c.x / cMag * size, c.y / cMag * size);
            cTrans = Point(cUnit.x, cUnit.y);
            
            //Arrow Head Start
            cPerp = Point(-cTrans.y, cTrans.x);
            arrowhead01 = Point(start.x + cPerp.x + cTrans.x, start.y + cPerp.y + cTrans.y);
            arrowhead02 = Point(start.x - cPerp.x + cTrans.x, start.y - cPerp.y + cTrans.y);
        }
        if (e) {
            //start-end vector: d
            d = Point(start.x - end.x, start.y - end.y);
            dMag = pointVecMag(d);
            dUnit = Point(d.x / dMag * size, d.y / dMag * size);
            dTrans = Point(dUnit.x, dUnit.y);
            
            //Arrow Head End
            dPerp = Point(-dTrans.y, dTrans.x);
            arrowhead03 = Point(end.x + dPerp.x + dTrans.x, end.y + dPerp.y + dTrans.y);
            arrowhead04 = Point(end.x - dPerp.x + dTrans.x, end.y - dPerp.y + dTrans.y);
        }
    };
    
    void draw_lines() const;
    
private:
    //Line
    Point start;
    Point end;
    
    //Arrowhead at start
    Point c;
    Point cUnit;
    Point cTrans;
    Point cPerp;
    double cMag;
    
    Point arrowhead01;
    Point arrowhead02;
    
    //Arrowhead at end
    Point d;
    Point dUnit;
    Point dTrans;
    Point dPerp;
    double dMag;
    
    Point arrowhead03;
    Point arrowhead04;
    
    bool s;
    bool e;
    int size;
};

void Arrow::draw_lines() const{
    
    if (color().visibility()) {
        //Line
        fl_line(start.x,start.y, end.x, end.y);
        //Arrowhead at start
        if (s) {
            fl_line(start.x, start.y, arrowhead01.x, arrowhead01.y);
            fl_line(start.x, start.y, arrowhead02.x, arrowhead02.y);
        }
        //Arrowhead at end
        if (e) {
            fl_line(end.x, end.y, arrowhead03.x, arrowhead03.y);
            fl_line(end.x, end.y, arrowhead04.x, arrowhead04.y);
        }
    }
}

/***********************************************************************************************
 **************************************** Ch13-08 **********************************************
 ***********************************************************************************************/
class Regular_hexagon: public Shape
{
public:
    Regular_hexagon(Point xy, int rr) : p(xy), r(rr)
    {
        a = Point {p.x + r, p.y};
        b = Point {p.x + (int)(cos(M_PI / 3) * r), p.y - (int)(sin(M_PI / 3) * r)};
        c = Point {p.x - (int)(cos(M_PI / 3) * r), p.y - (int)(sin(M_PI / 3) * r)};
        d = Point {p.x - r, p.y};
        e = Point {p.x - (int)(cos(M_PI / 3) * r), p.y + (int)(sin(M_PI / 3) * r)};
        f = Point {p.x + (int)(cos(M_PI / 3) * r), p.y + (int)(sin(M_PI / 3) * r)};
    }
    
    Point point() const { return p; };
    int radius() const { return r; };
    
    void draw_lines() const;
private:
    Point p;
    Point a, b, c, d, e, f;
    int r;
};

void Regular_hexagon::draw_lines() const
{
    fl_line(a.x, a.y, b.x, b.y);
    fl_line(b.x, b.y, c.x, c.y);
    fl_line(c.x, c.y, d.x, d.y);
    fl_line(d.x, d.y, e.x, e.y);
    fl_line(e.x, e.y, f.x, f.y);
    fl_line(f.x, f.y, a.x, a.y);
}

/***********************************************************************************************
 **************************************** Ch13-04 **********************************************
 ***********************************************************************************************/
Point n(Rectangle& r) { return Point{r.point(0).x + (r.width() / 2),r.point(0).y}; }

Point s(Rectangle& r) { return Point{r.point(0).x + (r.width() / 2),r.point(0).y + r.height()}; }

Point e(Rectangle& r) { return Point{r.point(0).x + r.width(),r.point(0).y + (r.height() / 2)}; }

Point w(Rectangle& r) { return Point{r.point(0).x,r.point(0).y + (r.height() / 2)}; }

Point center(Rectangle& r) { return Point{r.point(0).x + (r.width() / 2),r.point(0).y + (r.height() / 2)}; }

Point ne(Rectangle& r) { return Point{r.point(0).x + r.width(),r.point(0).y}; }

Point se(Rectangle& r) { return Point{r.point(0).x + r.width(),r.point(0).y + r.height()}; }

Point sw(Rectangle& r) { return Point{r.point(0).x,r.point(0).y + r.height()}; }

Point nw(Rectangle& r) { return Point{r.point(0).x,r.point(0).y}; }

/***********************************************************************************************
 **************************************** Ch13-05 **********************************************
 ***********************************************************************************************/
// Circle
Point n_circle(Circle& c) { return Point{c.point(0).x + c.radius(),c.point(0).y}; }

Point s_circle(Circle& c) { return Point{c.point(0).x + c.radius(),c.point(0).y + 2 * c.radius()}; }

Point e_circle(Circle& c) { return Point{c.point(0).x + 2 * c.radius(),c.point(0).y + c.radius()}; }

Point w_circle(Circle& c) { return Point{c.point(0).x,c.point(0).y + c.radius()}; }

Point center_circle(Circle& c) { return Point{c.point(0).x + c.radius(),c.point(0).y + c.radius()}; }

Point ne_circle(Circle& c) { return Point{c.point(0).x + c.radius() + (int)(cos(M_PI / 4) * c.radius()),c.point(0).y + c.radius() - (int)(sin(M_PI / 4) * c.radius())}; }

Point se_circle(Circle& c) { return Point{c.point(0).x + c.radius() +  (int)(cos(M_PI / 4) * c.radius()),c.point(0).y + c.radius() + (int)(sin(M_PI / 4) * c.radius())}; }

Point sw_circle(Circle& c) { return Point{c.point(0).x + c.radius() - (int)(cos(M_PI / 4) * c.radius()),c.point(0).y + c.radius() + (int)(sin(M_PI / 4) * c.radius())}; }

Point nw_circle(Circle& c) { return Point{c.point(0).x + c.radius() - (int)(cos(M_PI / 4) * c.radius()),c.point(0).y + c.radius() - (int)(cos(M_PI / 4) * c.radius())}; }

// Ellipse
Point n_ellipse(Ellipse& e) { return Point{e.point(0).x + e.major(),e.point(0).y}; }

Point s_ellipse(Ellipse& e) { return Point{e.point(0).x + e.major(),e.point(0).y + 2 * e.minor()}; }

Point e_ellipse(Ellipse& e) { return Point{e.point(0).x + 2 * e.major(),e.point(0).y + e.minor()}; }

Point w_ellipse(Ellipse& e) { return Point{e.point(0).x,e.point(0).y + e.minor()}; }

Point center_ellipse(Ellipse& e) { return Point{e.point(0).x + e.major(),e.point(0).y + e.minor()}; }

Point ne_ellipse(Ellipse& e) { return Point{e.point(0).x + e.major() + (int)(cos(M_PI / 4) * e.major()),e.point(0).y + e.minor() - (int)(sin(M_PI / 4) * e.minor())}; }

Point se_ellipse(Ellipse& e) { return Point{e.point(0).x + e.major() + (int)(cos(M_PI / 4) * e.major()),e.point(0).y + e.minor() + (int)(sin(M_PI / 4) * e.minor())}; }

Point sw_ellipse(Ellipse& e) { return Point{e.point(0).x + e.major() - (int)(cos(M_PI / 4) * e.major()),e.point(0).y + e.minor() + (int)(sin(M_PI / 4) * e.minor())}; }

Point nw_ellipse(Ellipse& e) { return Point{e.point(0).x + e.major() - (int)(cos(M_PI / 4) * e.major()),e.point(0).y + e.minor() - (int)(sin(M_PI / 4) * e.minor())}; }

#endif /* Header_h */
