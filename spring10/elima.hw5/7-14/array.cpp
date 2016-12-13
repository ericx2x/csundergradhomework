// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ex7.4.array.cpp
#include "array.h"

namespace ARRAY_NAMESPACE {

  template <typename T>
  Array<T>::Array(size_t size) : size_(size) {
    array_ = new T[size];
  }

  template <typename T>
  Array<T>::Array(const Array<T>& ar) : size_(ar.size_) {
    array_ = new T[ar.size_];
    for(size_t i = 0; i < size_; i++)
      array_[i] = ar.array_[i];
  }

  template <typename T>
  Array<T>& Array<T>::operator=(const Array<T>& ar) {
    if(this == &ar)
      return *this;
    if(size_ != ar.size_) {
      size_ = ar.size_;
      delete[] array_;
      array_ = new T[size_];
    }
    for(size_t i = 0; i < size_; i++)
      array_[i] = ar.array_[i];
    return *this;
  }

  template <typename T>
  Array<T>::~Array() {
    delete [] array_;
  }

  template <typename T>
  int Array<T>::size() const { 
    return size_;
  }

  template <typename T>
  T& Array<T>::operator[](int i) {
    return array_[i];
  }

  template <typename T>
  const T& Array<T>::operator[](int i) const {
    return array_[i];
  }

}

