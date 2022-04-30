#include "endpoint.h"

#include <vector>
#include <exception>

namespace BasicGraphics {

namespace Basic {

template<class T>
EndPoint<T>::EndPoint() {
    this->_coordinates = nullptr;
    this->_dimension=0;
}

template<class T>
EndPoint<T>::EndPoint(T *coordinates, size_t dimension) {
    this->_dimension=dimension;
    this->_coordinates = new T[dimension];
    for(size_t i = 0; i < dimension; i++) {
        this->_coordinates[i] = coordinates[i];
    }
}

template<class T>
EndPoint<T>::EndPoint(size_t dimension) {
    this->_dimension = dimension;
    this->_coordinates = new T[dimension];
    memset(this->_coordinates, (T)0,sizeof(this->_coordinates));
}

template<class T>
EndPoint<T>::EndPoint(size_t dimension, T fill_num) {
    this->_dimension = dimension;
    this->_coordinates = new T[dimension];
    memset(this->_coordinates, fill_num,sizeof(this->_coordinates));
}
template<class T>
inline T* to_endpoint(std::vector<T> coordinates) {
    int n = coordinates.size();
    T* endpoint = new T[n];
    for(int i = 0; i < coordinates.size(); i++) {
        endpoint[i] = coordinates[i];
    }
    return endpoint;
}

template<class T>
T& EndPoint<T>::operator[](unsigned int index) {
    if(index < 0 || index >= this->_dimension) {
        throw std::out_of_range("index out of range");
    }
    return this->_coordinates[index];
}

template<class T>
void EndPoint<T>::operator=(const EndPoint<T> &rhs) {
    delete this->_coordinates;
    size_t n = rhs.get_dimension();
    this->_dimension = n;
    this->_coordinates = new T[n];
    for(int i = 0; i < n; i++) {
        this->_coordinates[i] =rhs[i];
    }

}

template<class T>
bool EndPoint<T>::operator==(const EndPoint<T> &rhs) {
    if(this->_dimension != rhs.get_dimension()) {
        return false;
    }
    for(int i = 0; i < this->_dimension; i++) {
        if(this->_coordinates[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}

template<class T>
bool EndPoint<T>::operator!=(const EndPoint<T> &rhs) {
    if(this->_dimension != rhs.get_dimension()) {
        return true;
    }
    for(int i = 0; i < this->_dimension; i++) {
        if(this->_coordinates[i] != rhs[i]) {
            return true;
        }
    }
    return false;
}

template<class T>
EndPoint<T>& EndPoint<T>::operator+=(const EndPoint<T> &rhs) {
    if(this->_dimension != rhs.get_dimension()) {
        throw std::exception("dimension not equal");
    }
    for(int i = 0; i < this->_dimension; i++) {
        this->_coordinates[i] += rhs[i];
    }
    return *this;
}

template<class T>
EndPoint<T>& EndPoint<T>::operator+=(const T &rhs) {
    if(this->_dimension != rhs.get_dimension()) {
        throw std::exception("dimension not equal");
    }
    for(int i = 0; i < this->_dimension; i++) {
        this->_coordinates[i] += rhs;
    }
    return *this;
}

template<class T>
EndPoint<T>& EndPoint<T>::operator-=(const EndPoint<T> &rhs) {
    if(this->_dimension != rhs.get_dimension()) {
        throw std::exception("dimension not equal");
    }
    for(int i = 0; i < this->_dimension; i++) {
        this->_coordinates[i] -= rhs[i];
    }
    return *this;
}

template<class T>
EndPoint<T>& EndPoint<T>::operator-=(const T &rhs) {
    if(this->_dimension != rhs.get_dimension()) {
        throw std::exception("dimension not equal");
    }
    for(int i = 0; i < this->_dimension; i++) {
        this->_coordinates[i] -= rhs;
    }
    return *this;
}

template<class T>
EndPoint<T>& EndPoint<T>::operator*=(const EndPoint<T> &rhs) {
    if(this->_dimension != rhs.get_dimension()) {
        throw std::exception("dimension not equal");
    }
    for(int i = 0; i < this->_dimension; i++) {
        this->_coordinates[i] *= rhs[i];
    }
    return *this;
}

template<class T>
EndPoint<T>& EndPoint<T>::operator*=(const T &rhs) {
    if(this->_dimension != rhs.get_dimension()) {
        throw std::exception("dimension not equal");
    }
    for(int i = 0; i < this->_dimension; i++) {
        this->_coordinates[i] *= rhs;
    }
    return *this;
}

template<class T>
EndPoint<T>& EndPoint<T>::operator/=(const EndPoint<T> &rhs) {
    if(this->_dimension != rhs.get_dimension()) {
        throw std::exception("dimension not equal");
    }
    for(int i = 0; i < this->_dimension; i++) {
        this->_coordinates[i] /= rhs[i];
    }
    return *this;
}

template<class T>
EndPoint<T>& EndPoint<T>::operator/=(const T &rhs) {
    if(this->_dimension != rhs.get_dimension()) {
        throw std::exception("dimension not equal");
    }
    for(int i = 0; i < this->_dimension; i++) {
        this->_coordinates[i] /= rhs;
    }
    return *this;
}

template<class T>
inline EndPoint<T> operator+(EndPoint<T> lhs, const EndPoint<T> &rhs) {
    lhs += rhs;
    return lhs;
}

template<class T>
inline EndPoint<T> operator+(EndPoint<T> lhs, const T &rhs) {
    lhs += rhs;
    return lhs;
}

template<class T>
inline EndPoint<T> operator-(EndPoint<T> lhs, const EndPoint<T> &rhs) {
    lhs -= rhs;
    return lhs;
}

template<class T>
inline EndPoint<T> operator-(EndPoint<T> lhs, const T &rhs) {
    lhs -= rhs;
    return lhs;
}

template<class T>
inline EndPoint<T> operator*(EndPoint<T> lhs, const EndPoint<T> &rhs) {
    lhs *= rhs;
    return lhs;
}

template<class T>
inline EndPoint<T> operator*(EndPoint<T> lhs, const T &rhs) {
    lhs *= rhs;
    return lhs;
}

template<class T>
inline EndPoint<T> operator/(EndPoint<T> lhs, const EndPoint<T> &rhs) {
    lhs /= rhs;
    return lhs;
}

template<class T>
inline EndPoint<T> operator/(EndPoint<T> lhs, const T &rhs) {
    lhs /= rhs;
    return lhs;
}

}//namespace Basic
}//namespace BasicGraphics
