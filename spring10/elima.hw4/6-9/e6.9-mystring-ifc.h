/***************************************/
/* Eric Lima                           */
/*                                     */
/* Exercise 6-9                        */
/*                                     */
/* Computing 4                         */
/***************************************/
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 6-9
  // File: e6.9-mystring-ifc.h
  // Abstract interface for several string operations, which will be adopted using std::string
#ifndef E6_9_MYSTRING_IFC_H
#define  E6_9_MYSTRING_IFC_H  
#include <stdexcept>
namespace MyString {

  class StringIfc {
  public:
  //  typedef std::string::size_type size;	// size of a string
    virtual int strpos(char) const = 0;		// position of char, -1 if not found
    virtual int strlen() const = 0;		// length of a string

    virtual char at(int) ; // character at position i
  };

}
#endif
 
