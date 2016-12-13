// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ex7.3.stack.cpp
// Implementation of stack operations for Exercise 7-3
#include "stack.h"
typedef int size_t;
template <typename T, size_t SIZE> 
Stack<T, SIZE >::Stack() : top_(0) { }

template <typename T, size_t SIZE> 
Stack<T, SIZE >::~Stack() { }

template <typename T, size_t SIZE> 
void Stack<T, SIZE >::push(const T& new_item) {
  stack_[top_++] = new_item;   
}

template <typename T, size_t SIZE> 
void Stack<T, SIZE >::pop() {
  --top_;
}

template <typename T, size_t SIZE> 
void Stack<T, SIZE >::top(T& item) const {
  item = stack_[top_ - 1];
}

template <typename T, size_t SIZE> 
bool Stack<T, SIZE >::is_empty() const {
  return top_ == 0;
}

template <typename T, size_t SIZE> 
bool Stack<T, SIZE >::is_full() const {
  return top_ == SIZE;
}
