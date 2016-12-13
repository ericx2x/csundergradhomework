  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File e5.2-rbook.cpp
  // Exercise 5.2
  // Implementation for class ReferenceBook
#include "e5.2-rbook.h"
  ReferenceBook::ReferenceBook(const string& name, char c) : Book(name), subject_(c) {}
   void ReferenceBook::info() const {
     cout << "reference book " << Book::get() << " for course " << subject_ << endl;
   }
   char ReferenceBook::get() const {
      return subject_;
   }

