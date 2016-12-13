#include "Queue.h"

template <typename T, int n>
Queue<T,n>::Queue() : f(0), b(0), s(0) {};

template <typename T, int n>
bool Queue<T,n>::empty() {
  return s == 0;
}

template <typename T, int n>
bool Queue<T,n>::full() {
  return s == n;
}

template <typename T, int n>
void Queue<T,n>::insert(T item) {
  if(!full()) {
    data[b] = item;
    s++;
    if(b == n) b = 0;
    else b++;
  }
}

template <typename T, int n>
T Queue<T,n>::front() {
  if(!empty()) {
    return data[f];
  }
}

template <typename T, int n>
void Queue<T,n>::remove() {
  if(!empty()) {
    s--;
    if(f == n) f = 0;
    else f++;
  }
}

template <typename T, int n>
void Queue<T,n>::makenull() {
  f = 0;
  b = 0;
  s = 0;
}

template <typename T, int n>
int Queue<T,n>::size() {
  return s;
}

