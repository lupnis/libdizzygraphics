#ifndef VECTOR_H
#define VECTOR_H

#include "endpoint.h"

namespace BasicGraphics {
namespace Basic {

template<class T>
class Vector
{
public:
    /*Constructors and Destructor*/
    Vector();
    Vector(T* start, T* end, size_t dimension);
    Vector(T* end, size_t dimension);
    Vector(size_t dimension);
    Vector(EndPoint<T> start, EndPoint<T> end);
    Vector(EndPoint<T> end);
    ~Vector() throw() {}

    /*Basic Operators*/
    T& operator[](unsigned int index);
    void operator=(const Vector &rhs);
    bool operator==(const Vector &rhs);
    bool operator!=(const Vector &rhs);

    /*Calculative Operators*/
    Vector& operator+=(const Vector &rhs);
    Vector& operator+=(const T &rhs);
    Vector& operator-=(const Vector &rhs);
    Vector& operator-=(const T &rhs);
    Vector& operator*=(const Vector &rhs);
    Vector& operator*=(const T &rhs);
    Vector& operator/=(const Vector &rhs);
    Vector& operator/=(const T &rhs);

    size_t get_dimension() {
        return this->pstart.get_dimension();
    }

private:
    EndPoint<T> pstart, pend;
};

}//namespace Basic
}//namespace BasicGraphics

#endif // VECTOR_H
