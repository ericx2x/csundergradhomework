  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File e5.2-tbook.cpp
  // Exercise 5.2
  // Implementation for class TextBook
#include "e5.2-tbook.h"
  TextBook::TextBook(const string& name, int c) : Book(name), course_(c) {}
   void TextBook::info() const {
     cout << "text book " << Book::get() << " for course " << course_ << endl;
   }
   int TextBook::get() const {
      return course_;
   }

