#include "endpoint.h"

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
EndPoint<T>::EndPoint(std::vector<T>& coordinates) {
    this->_dimension = coordinates.size();
    this->_coordinates = new T[this->_dimension];
    for(size_t i = 0; i < this->_dimension; i++) {
        this->_coordinates[i] = coordinates[i];
    }
}


template<class T>
T& EndPoint<T>::operator[](unsigned int index) {
    if(index <0 || index>=this->_dimension) throw std::out_of_range("index out of range");
    return this->_coordinates[index];
}

template<class T>
void EndPoint<T>::operator=(EndPoint<T>&_)
{
    if(this->_dimension!=_.get_dimension()) {
        throw std::exception("dimension not equal");
    }
    for(int i = 0; i <this->_dimension;i++) {
        this->_coordinates[i] =_[i];
    }

}

template<class T>
bool EndPoint<T>::operator==(EndPoint<T>& _) {
    if(this->_dimension!=_.get_dimension()) {
        return false;
    }
    for(int i = 0; i < this->_dimension; i++) {
        if(this->_coordinates[i] != _[i]) {
            return false;
        }
    }
    return true;
}

template<class T>
bool EndPoint<T>::operator!=(EndPoint<T>& _) {
    if(this->_dimension!=_.get_dimension()) {
        return true;
    }
    for(int i = 0; i < this->_dimension; i++) {
        if(this->_coordinates[i] != _[i]) {
            return true;
        }
    }
    return false;
}


}//namespace Basic
}//namespace BasicGraphics
