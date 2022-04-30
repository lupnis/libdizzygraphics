#include "vector.h"

#include <vector>
#include <exception>

namespace BasicGraphics {
namespace Basic {

template<class T>
Vector<T>::Vector() {
}
template<class T>
Vector<T>::Vector(T* start, T* end, size_t dimension) {
    this->pstart = EndPoint<T>(start, dimension);
    this->pend = EndPoint<T>(end,dimension);
}

template<class T>
Vector<T>::Vector(T* end, size_t dimension) {
    this->pstart = EndPoint<T>(dimension);
    this->pend = EndPoint<T>(end,dimension);
}

template<class T>
Vector<T>::Vector(size_t dimension) {
    this->pstart = this->pend = EndPoint<T>(dimension);
}

template<class T>
Vector<T>::Vector(EndPoint<T> start, EndPoint<T> end) {
    this->pstart=start;
    this->pend = end;
}

template<class T>
Vector<T>::Vector(EndPoint<T> end) {
    this->pstart = EndPoint<T>(end.get_dimension());
    this->pend = end;
}

template<class T>
T& Vector<T>::operator[](unsigned int index) {
    if(index < 0 || index >= this->pend.get_dimension()) {
        throw std::out_of_range("index out of range");
    }
    return this->pend[index] - this->pstart[index];
}

}//namespace Basic
}//namespace BasicGraphics
