  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File e5.2-tbook.h
  // Exercise 5.2
  // Interface for class TextBook
#ifndef E5_2_TBOOK_H	
#define E5_2_TBOOK_H  
#include <string>
#include "e5.2-book.h"  

// The TextBook class is declared here as well as private members and public 
// variables. This is an function that computes the course information. 
// The constructor recieves a value and creates an unique variable.

  class TextBook : public Book {
  public:
    TextBook(const string&, int); //Constructor with 2 args
    virtual void info() const;//A virtual info func. Runtime gets right versions
    int get() const;//retursn course number
  private:
    int course_;
  };
#endif
