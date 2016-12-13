  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 5.6
  // Implementation for class PostAddress
  // File: e5.6-address-post.cpp
#include <string>

#include "e5.6-address-post.h"
namespace e56 {
  PostAddress::PostAddress(const string& n, const string& a, 
          const string& z, const string& p) :
    ExtendedAddress(n, a, z), postbox_(p) {
  }
   // PostAddress::~PostAddress() {

  PostAddress::PostAddress(const PostAddress& p) : ExtendedAddress(p) {}
    
  PostAddress& PostAddress::operator=(const PostAddress& p) {
    if(this == &p)
      return *this;
    ExtendedAddress::operator=(p);
    postbox_ = p.postbox_;
    return *this;
  }

  string PostAddress::postbox() const {
    return postbox_;
  }
}
