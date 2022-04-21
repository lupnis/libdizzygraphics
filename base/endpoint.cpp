#include "endpoint.h"

#include <vector>
#include <string>
#include <exception>

namespace BasicGraphics {

namespace Basic {

template<class T, class _Vec>
EndPoint<T,_Vec>::EndPoint() {
    this->_coordinates = nullptr;
    this->_dimension=0;
}

template<class T, class _Vec>
EndPoint<T,_Vec>::EndPoint(T *coordinates, size_t dimension) {
    this->_dimension=dimension;
    this->_coordinates = new T[dimension];
    for(size_t i = 0; i < dimension; i++) {
        this->_coordinates[i] = coordinates[i];
    }
}

template<class T, class _Vec>
EndPoint<T,_Vec>::EndPoint(size_t dimension) {
    this->_dimension = dimension;
    this->_coordinates = new T[dimension];
    memset(this->_coordinates, (T)0,sizeof(this->_coordinates));
}

template<class T, class _Vec>
EndPoint<T,_Vec>::EndPoint(size_t dimension, T fill_num) {
    this->_dimension = dimension;
    this->_coordinates = new T[dimension];
    memset(this->_coordinates, fill_num,sizeof(this->_coordinates));
}

template<class T, class _Vec>
EndPoint<T,_Vec>::EndPoint(_Vec coordinates) {
    this->_dimension = coordinates.size();
    this->_coordinates = new T[coordinates.size()];
    for(int i = 0; i < coordinates.size(); i++) {
        this->_coordinates[i] = coordinates[i];
    }
}

template<class T, class _Vec>
void EndPoint<T,_Vec>::operator=(EndPoint<T,_Vec>&_)
{
    if(this->_dimension!=_.get_dimension()) {
        throw std::exception("dimension not equal");
    }
    for(int i = 0; i <this->_dimension;i++) {
        this->_coordinates[i] =
    }

}



}//namespace Basic
}//namespace BasicGraphics
