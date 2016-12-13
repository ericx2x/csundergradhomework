// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ex7.4.array.h
#ifndef EX7_4_ARRAY_H
#define EX7_4_ARRAY_H
#include <stdexcept>
//typedef int size_t;
namespace ARRAY_NAMESPACE {
    template <typename T> 
      // T is a model of Default Constructible
      class Array {
      public:
      Array(size_t = 100);
      Array(const Array<T>&);
      Array<T>& operator=(const Array<T>&);
      virtual ~Array();
      virtual const T& operator[](int) const;
      virtual T& operator[](int);
      int size() const;
      typedef T element_type;  // see below
      protected:
      size_t size_;
      T* array_;
    };

  }
#endif
