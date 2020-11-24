//
//  main.cpp
//  Ch19-06
//
//  Created by Stefan Diaconu on 23/11/2020.
//

#include <iostream>

template<typename T> class Number {
    T* val;
public:
    Number() : val{0} {}
    Number(const Number& arg) : val{arg.val} {}
    Number(T&& v) : val{&v} {}
    Number& operator=(const Number& v) { val = v.val; return *this; }
    Number& operator=(Number&& v) { val = v.val; return *this; }
    
    T get() const { return *val; };
};

template<typename T> T operator+(const T& v1, const T& v2)
{
    return T(v1.get() + v2.get());
}

template<typename T> T operator-(const T& v1, const T& v2)
{
    return T(v1.get() - v2.get());
}

template<typename T> T operator*(const T& v1, const T& v2)
{
    return T(v1.get() * v2.get());
}

template<typename T> T operator/(const T& v1, const T& v2)
{
    return T(v1.get() / v2.get());
}

template<typename T> T operator%(const T& v1, const T& v2)
{
    return T(v1.get() % v2.get());
}

template<typename T> std::ostream& operator<<(std::ostream& os, Number<T>& i)
{
    return os << i.get();
}

template<typename T> std::ostream& operator<<(std::ostream& os, const Number<T>& i)
{
    return os << i.get();
}

int main(int argc, const char * argv[]) {
    Number<int> i1;
    i1 = 7;
    Number<double> i2 = 2.0;
    Number<double> i3(i2);
    Number<int> i4;
    i4 = i1;
    Number<int> i5 = 6;
    std::cout << "i1 (default constructed): " << i1 << "\n";
    std::cout << "i2 (constructed with argument): " << i2 << "\n";
    std::cout << "i3 (copy constructed from i2): " << i3 << "\n";
    std::cout << "i4 (copy assigned  from i1): " << i4 << "\n";
    std::cout << "i5 (constructed with argument): " << i5 << "\n";
    std::cout << "i2 + i3 = " << i2 + i3 << "\n";
    std::cout << "i3 - i2 = " << i3 - i2 << "\n";
    std::cout << "i4 * i5 = " << i4 * i5 << "\n";
    std::cout << "i5 / i4 = " << i5 / i4 << "\n";
    std::cout << "i4 % i5 = " << i4 % i5 << "\n";

    return 0;
}
