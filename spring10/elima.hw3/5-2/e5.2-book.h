  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File e5.2-book.h
  // Exercise 5.2
  // Interface for class Book



#ifndef E5_2_BOOK_H	
#define E5_2_BOOK_H  
#include <string>

// The Book class is declared here as well as private members and public 
// variables. This is an ordinary function. The constructor recieves a value  
// and creates on an unique variable.

class Book {

  public:
    Book(const string&);//constructor which takes an arg of a string.
    virtual ~Book();//a destructor.
    virtual void info() const = 0;//a virtual info function.
    string get() const;//query which returns the name variable.
  private:
    string name_;
  };

#endif
