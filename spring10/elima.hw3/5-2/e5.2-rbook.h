  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File e5.2-rbook.h 
  // Exercise 5.2
  // Interface for class TextBook
#ifndef E5_2_RBOOK_H	
#define E5_2_RBOOK_H  
#include <string>
#include "e5.2-book.h"

// The ReferenceBook class is declared here as well as private members and public 
// variables. This is an straightforward function. The constructor recieves a 
// value and creates an unique variable. 

  class ReferenceBook : public Book {
  public:
    ReferenceBook(const string&, char); //constructor with two args.
    virtual void info() const; //virtual function whic uses lazybinding
    char get() const;//query which returns a char.
  private:
    char subject_;
  };
#endif
