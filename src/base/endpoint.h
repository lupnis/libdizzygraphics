#ifndef ENDPOINT_H
#define ENDPOINT_H

namespace BasicGraphics {
namespace Basic {

template<class T>
class EndPoint {
public:
    /*Constructors and Destructor*/
    EndPoint();
    EndPoint(T* coordinates, size_t dimension);
    EndPoint(size_t dimension);
    EndPoint(size_t dimension, T fill_num);
    ~EndPoint() throw() { delete _coordinates; }

    /*Basic Operators*/
    T& operator[](unsigned int index);
    void operator=(const EndPoint &rhs);
    bool operator==(const EndPoint &rhs);
    bool operator!=(const EndPoint &rhs);

    /*Calculative Operators*/
    EndPoint& operator+=(const EndPoint &rhs);
    EndPoint& operator+=(const T &rhs);
    EndPoint& operator-=(const EndPoint &rhs);
    EndPoint& operator-=(const T &rhs);
    EndPoint& operator*=(const EndPoint &rhs);
    EndPoint& operator*=(const T &rhs);
    EndPoint& operator/=(const EndPoint &rhs);
    EndPoint& operator/=(const T &rhs);

    size_t get_dimension() { return this->_dimension; }

private:
    T* _coordinates;
    size_t _dimension;
};
}//namespace Basic
}//namespace BasicGraphics

#endif // ENDPOINT_H
