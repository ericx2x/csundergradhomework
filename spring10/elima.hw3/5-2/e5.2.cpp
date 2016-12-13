  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 5.2
  // File: e5.2.cpp
  // Main program for the simaple database of books
 
  #include <iostream>
  using namespace std;
  #include "e5.2-tbook.h"
  #include "e5.2-rbook.h"
  #include "e5.2-book.h"

  void show(const Book* const b[], int size) {
    for(int i = 0; i < size; ++i) 
      b[i]->info();
  }

  int main() {
   const int Size = 2;
   Book* base[Size];
   base[0] = new TextBook("OOPS", 3773);
   base[1] = new ReferenceBook("Relativity Theory", 'p');
   show(base, Size);
   // RTTI
   for(int i = 0; i < Size; ++i) 
     if(ReferenceBook* p = dynamic_cast<ReferenceBook*>(base[i])) 
        cout << "subject = " << p->get() << endl;
 }

