  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 5.6
  // Interface for class PostAddress
  // File: e5.6-address-post.h
#ifndef E5_6_ADDRESS_POST_H
#define E5_6_ADDRESS_POST_H 
#include <string>
#include "e5.6-address-extended.h"

// The PostAddress class is declared here as well as private members and public 
// variables. This is a function that computes the postbox. 
// The constructor recieves a value and creates an unique variable.

namespace e56 {
class PostAddress : public ExtendedAddress {
public:
  PostAddress(const string&, const string&, const string&, const string&);
  PostAddress(const PostAddress&);
  PostAddress& operator=(const PostAddress&);

  string postbox() const;
  private:
  string postbox_;
};
}
#endif
