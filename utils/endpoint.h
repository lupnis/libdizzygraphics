#ifndef ENDPOINT_H
#define ENDPOINT_H


namespace BasicGraphics {
namespace Basic {

template<class T, class _Vec>
class EndPoint {
public:
    EndPoint();
    EndPoint(T* coordinates, size_t dimension);
    EndPoint(size_t dimension);
    EndPoint(size_t dimension, T fill_num);
    EndPoint(_Vec coordinates);
    ~EndPoint() throw() { delete _coordinates; }

    void operator=(EndPoint& _);
    bool operator==(EndPoint& _);
    bool operator!=(EndPoint& _);
    T operator[](unsigned int index);

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
