#include "vector.h"

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

}






}//namespace Basic
}//namespace BasicGraphics
