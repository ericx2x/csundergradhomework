// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ex7.3.stack.h
#ifndef EX7_3_STACK_H
#define  EX7_3_STACK_H 
  template <typename T, int SIZE> 
  class Stack {
  public:
    Stack(); 
    ~Stack();
    void push(const T& new_item);
    void pop();
    void top(T& item) const;
    bool is_empty() const;
    bool is_full() const;
  private:
    int top_;   
    T stack_[SIZE];   
  };
#endif
  
