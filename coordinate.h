#ifndef COORDINATE_H
#define COORDINATE_H
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <time.h>
template <class T>
class Coordinate{
    T x;
    T y;
    public:
    //Constructors
    Coordinate(T x = 0, T y = 0) : x(x), y(y) {}
    //Getters
    T getX() const{
        return x;
    }
    T getY() const{
        return y;
    }
    //Setters
    void setX(const T newVal){
        x = newVal;
    }
    void setY(const T newVal){
        y = newVal;
    }
    // Output operator overload
    template <typename U>
    friend ostream& operator<<(ostream& os, const Coordinate<T>& rhs);
};
template <typename U>
ostream& operator<<(ostream& os, const Coordinate<U>& rhs){
        os << rhs.getX() << ", " << rhs.getY() << endl;
        return os;
    }
#endif