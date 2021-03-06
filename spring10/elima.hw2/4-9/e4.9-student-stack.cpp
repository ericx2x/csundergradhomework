  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: e3.9-student-stack.cpp
  // Implementation of Student stack operations

  #include "e4.9-student.h"
  #include "e4.9-student-stack.h"

// This segement of Namespace to utilize the stack operations

namespace e4_9 {

  // canonical construction is used here

  StudentStack::StudentStack(int size) {
    top_ = -1;
    size_ = size;
    stack_ = new Student[size];
    errorState_ = STACK_OK;
  }

  StudentStack::StudentStack(const StudentStack& s) {
    top_ = s.top_;
    size_ = s.size_;
    stack_ = new Student[size_];
    for(int i = 0; i <= top_; ++i)
      stack_[i] = s.stack_[i];
    errorState_ = s.errorState_;
  }

  StudentStack& StudentStack::operator=(const StudentStack& s) {
    if(this == &s)
      return *this;
    if(size_ != s.size_) {
      delete [] stack_;
      stack_ = new Student[s.size_];
    }
    top_ = s.top_;
    size_ = s.size_;
    for(int i = 0; i <= top_; ++i)
      stack_[i] = s.stack_[i];
    errorState_ = s.errorState_;
    return *this;
  }

  StudentStack::~StudentStack() {
    delete [] stack_;
  }

// stack operations are here

  void StudentStack::push(const Student& i) {
    if(top_ == size_ - 1) { // full
      errorState_ = STACK_FULL;
      return;
    }
    stack_[++top_] = i;
    errorState_ = STACK_OK;
  }

  const Student& StudentStack::top() const {
    if(top_ == -1) { // empty
      errorState_ = STACK_EMPTY;
      return *(new Student); // must return something, but this leaks memory
            // exception handling is superior
    }
   
    errorState_ = STACK_OK;
    return stack_[top_];
  }

  void StudentStack::pop() {
    if(top_ == -1) { // empty
      errorState_ = STACK_EMPTY;
      return;
    }
   
    errorState_ = STACK_OK;
    top_--;
  }
   
  bool StudentStack::empty() const {
    return top_ == -1;
  }

  bool StudentStack::full() const {
    return top_ == size_ -1;
  }

  void StudentStack::clearError() {
    errorState_ = STACK_OK;
  }

  StudentStack::ErrorState StudentStack::getError() const {
    return errorState_;
  }
}

