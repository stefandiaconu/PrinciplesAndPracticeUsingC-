//
//  main.cpp
//  Ch19-08
//
//  Created by Stefan Diaconu on 24/11/2020.
//

#include "../../std_lib_facilities.h"

template<typename T> class allocatr {
public:
    T* allocate(int n);                                     // allocate space for n objects of type T
    void deallocate(T* p, int n) { free(p); };              // deallocate n objects of type T starting at p
    
    void construct(T* p, const T& v) { new(p) T(v); };      // construct a T with the value v in p
    void destroy(T* p) { p->~T(); };                        // destroy the T in p
};

template<typename T> T* allocatr<T>::allocate(int n)
{
    T* p = static_cast<T*>(malloc(n*sizeof(T)));
    if (p == 0) error("allocate: could not allocate memory");
    return p;
}

template<typename T, typename A = allocatr<T> >
class vectr {   // read "for all types T" (just like in math)
    A alloc;
    int sz;     // the size
    T* elem;    // a pointer to the elements
    int space;  // size + free space
    
public:
    vectr() : sz{0}, elem{nullptr}, space{0} {}
    explicit vectr(int s) : sz{s}, elem{new T[s]}, space{s}
    {
        for (int i=0; i<sz; ++i) elem[i] = 0;   // elements are initialized
    }
    
    vectr(const vectr&);                                      // copy constructor
    vectr& operator=(const vectr&);                           // copy assignment
    
    vectr(vectr&&);                                           // move constructor
    vectr& operator=(vectr&&);                                // move assignment
    
    ~vectr() { delete[] elem; }                                // destructor
    
    T& at(int n);                                               // checked access
    const T& at(int n) const;                                   // checked access
    
    T& operator[](int n); //{ return elem[n]; }                 // access: return reference
    const T& operator[](int n) const { return elem[n]; }
    
    int size() const { return sz; }                             // the current size
    int capacity() const {return space; }
    
    void resize(int newsize, T val = T());                      // growth
    void push_back(const T& d);
    void reserve(int newalloc);
};

template<typename T, typename A> T& vectr<T,A>::at(int n)
{
    if (n<0 || sz<=n) throw Range_error{n};
    return elem[n];
}

template<typename T, typename A> T& vectr<T,A>::operator[](int n)
{
    if (n<0 || sz<=n) throw Range_error{n};
    return elem[n];
}

template<typename T, typename A>
void vectr<T,A>::reserve(int newalloc)
{
    if (newalloc <= space) return;                              // never decrease allocation
    T* p = alloc.allocate(newalloc);                            // allocate new space
    for (int i=0; i<sz; ++i) alloc.construct(&p[i], elem[i]);   // copy
    for (int i=0; i<sz; ++i) alloc.destroy(&elem[i]);           // destroy
    alloc.deallocate(elem, space);                              // deallocate old space
    elem = p;
    space = newalloc;
}

template<typename T, typename A>
void vectr<T,A>::push_back(const T &val)
{
    if (space == 0) reserve(8);                                 // start with space for 8 elements
    else if (sz == space) reserve(2*space);                     // get more space
    alloc.construct(&elem[sz], val);                            // add val at end
    ++sz;                                                       // increase the size
}

template<typename T, typename A>
void vectr<T,A>::resize(int newsize, T val)
{
    reserve(newsize);
    for (int i=sz; i<newsize; ++i) alloc.construct(&elem[i], val);  // construct
    for (int i=newsize; i<sz; ++i) alloc.destroy(&elem[i]);         // destroy
    sz = newsize;
}

int main(int argc, const char * argv[]) {
    vectr<int> v1(0);
    v1.push_back(5);
    v1.push_back(3);
    v1.push_back(2);
    v1.push_back(5);
    v1.push_back(1);
    for (int i=0; i<v1.size(); ++i) {
        cout << v1[i] << endl;
    }
    
    std::allocator<int> a;
    
    return 0;
}
