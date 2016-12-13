#ifndef _QUEUE
#define _QUEUE

template <typename T, int n>
class Queue {

 protected:
  T data[n];
  int f;
  int b;
  int s;

 public: 
  Queue();
  bool empty();
  bool full();
  void insert(T item);
  T front();
  void remove();
  void makenull();
  int size();

};


#endif
