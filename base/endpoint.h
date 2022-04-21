#ifndef ENDPOINT_H
#define ENDPOINT_H

#include <vector>

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
    EndPoint(std::vector<T>& coordinates);
    ~EndPoint() throw() { delete _coordinates; }

    /*Basic Operators*/
    T& operator[](unsigned int index);
    void operator=(EndPoint& _);
    bool operator==(EndPoint& _);
    bool operator!=(EndPoint& _);

    /*Calculative Operators*/
    EndPoint operator+(EndPoint& _);
    EndPoint operator+(T& _);
    EndPoint operator+=(EndPoint& _);
    EndPoint operator+=(T& _);
    EndPoint operator-(EndPoint& _);
    EndPoint operator-(T& _);
    EndPoint operator-=(EndPoint& _);
    EndPoint operator-=(T& _);
    EndPoint operator*(EndPoint& _);
    EndPoint operator*(T& _);
    EndPoint operator*=(EndPoint& _);
    EndPoint operator*=(T& _);
    EndPoint operator/(EndPoint& _);
    EndPoint operator/(T& _);
    EndPoint operator/=(EndPoint& _);
    EndPoint operator/=(T& _);

    inline size_t get_dimension() { return this->_dimension; }
private:
    T* _coordinates;
    size_t _dimension;
};
}//namespace Basic
}//namespace BasicGraphics

#endif // ENDPOINT_H
