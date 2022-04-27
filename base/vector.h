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
    Vector(size_t dimension, T fill_num);
    Vector(EndPoint<T> start, EndPoint<T> end);
    Vector(EndPoint<T> end);

    /*Basic Operators*/
    T& operator[](unsigned int index);
    void operator=(const Vector &rhs);
    bool operator==(const Vector &rhs);
    bool operator!=(const Vector &rhs);

private:
    EndPoint<T> pstart, pend;
};

}//namespace Basic
}//namespace BasicGraphics

#endif // VECTOR_H
