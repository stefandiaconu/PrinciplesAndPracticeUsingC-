//
//  Chrono.cpp
//  Ch09TheDrill
//
//  Created by Stefan Diaconu on 03/05/2019.
//  Copyright © 2019 Stefan Diaconu. All rights reserved.
//

// Chrono.cpp
#include "Chrono.h"

namespace Chrono {
    // member function definitions:
    
    Date::Date(int yy, Month mm, int dd)
        :y{yy},m{mm},d{dd}
    {
        if (!is_date(yy, mm, dd)) throw Invalid{};
    }
    
    const Date& default_date()
    {
        static Date dd {1970, Month::jan, 1};   // start of the 21st century
        return dd;
    }
    
    Date::Date()
        :y{default_date().year()},
        m{default_date().month()},
        d{default_date().day()}
    {
    }
    
    void Date::add_day(int n)
    {
        if (m==Month::feb && (d==28 || d==29)) {
            add_month(n);
            d = 1;
        }
        else if ((m==Month::apr || m==Month::jun || m==Month::sep || m==Month::nov) && d==30) {
            add_month(n);
            d = 1;
        }
        else {
            add_month(n);
            d = 1;
        }
    }
    
    void Date::add_month(int n)
    {
        if (m==Month::dec) {
            m = Month::jan;
        }
        else if ((m==Month::jan && !leapyear(y)) && (d==29 || d==30 || d==31)) {
            d = 28;
            m = static_cast<Month>(static_cast<int>(m) + n);
        }
        else if ((m==Month::jan && leapyear(y)) && (d==30 || d==31)) {
            d = 29;
            m = static_cast<Month>(static_cast<int>(m) + n);
        }
        else {
            m = static_cast<Month>(static_cast<int>(m) + n);
        }
    }
    
    void Date::add_year(int n)
    {
        if (m==Month::feb && d==29 && !leapyear(y+n)) { // beware of leap year!
            m = Month::mar;         // use March 1 instead of February 29
            d = 1;
        }
        y += n;
    }
    
    // helper functions:
    bool is_date(int y, Month m, int d)
    {
        // assume that y is valid
        
        if (d <= 0) return false;           // d must be positive
        if (m < Month::jan || Month::dec < m) return false;
        
        int days_in_month = 31;             // most months have 31 days
        
        switch (m) {
            case Month::feb:                // the length of February varies
                days_in_month = (leapyear(y)) ? 29 : 28;
                break;
            case Month::apr: case Month::jun: case Month::sep: case Month::nov:
                days_in_month = 30;         // the rest have 30 days
        }
        
        if (days_in_month < d) return false;
        
        return true;
    }
    
    bool leapyear(int y)
    {
        return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
    }
    
    bool operator==(const Date& a, const Date& b)
    {
        return a.year()==b.year() && a.month()==b.month() && a.day()==b.day();
    }
    
    bool operator!=(const Date& a, const Date& b)
    {
        return !(a==b);
    }
    
    ostream& operator<<(ostream& os, const Date& d)
    {
          return os <<'('<<d.year()
                    <<','<<(int)d.month()
                    <<','<<d.day()<<')';
    }
    
    istream& operator>>(istream& is, Date& dd)
    {
            int y,m,d;
            char ch1,ch2,ch3,ch4;
            is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
            if (!is) return is;
            if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')' ) {
                is.clear(ios_base::failbit);
                return is;
            }
        
            dd = Date(y,Month(m),d);
        
            return is;
    }
    
    Day day_of_week(const Date& d)
    {
        //...
        return {};
    }
    
    Date next_Sunday(const Date d)
    {
        //...
        return d;
    }
    
    Date next_weekday(const Date& d)
    {
        //...
        return d;
    }
    
    Date next_workday(const Date& d) {
        //...
        return {};
    }
    
    Date week_of_year(const Date& d) {
        //...
        return {};
    }
    
}   /// Chrono

int main(int argc, char *argv[]) {
    // insert code here...
    /* 9.7.1 */
    Chrono::Date d{2004,Chrono::Month::feb,29};
    
    cout << d << endl;
    
    d.add_year(1);
    
    cout << d << endl;
    
    d.add_month(1);
    
    cout << d << endl;
    
    Chrono::Date d2{2005,Chrono::Month::jan,28};
    
    cout << d2 << endl;
    
    d2.add_month(1);
    
    cout << d2 << endl;
    
    Chrono::Date d3{2004,Chrono::Month::mar,31};
    
    cout << d3 << endl;
    
    d3.add_day(1);
    
    cout << d3 << endl;
    cout << endl;
    
    return 0;
}
