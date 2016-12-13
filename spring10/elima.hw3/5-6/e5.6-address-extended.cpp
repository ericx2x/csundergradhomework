
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 5.6
  // Implementation for class ExtendedAddress
  // File: e5.6-address-extended.cpp
#include "e5.6-address.h"
#include "e5.6-address-extended.h"
namespace e56 {
   
  ExtendedAddress::ExtendedAddress(const string& a, const string& n, const string& z):
      rep_(new Address(a, n)), zip_(z) {
  } 
  ExtendedAddress::ExtendedAddress(const ExtendedAddress& e) {
    rep_ = new Address(*(e.rep_));
    zip_ = e.zip_;
  }
  ExtendedAddress::~ExtendedAddress() {
    delete rep_;
  }
  ExtendedAddress& ExtendedAddress::operator=(const ExtendedAddress& e) {
    if(this != &e) {
      delete rep_;
      rep_ = new Address(e.name(), e.address());
      zip_ = e.zip_;  
    }
    return *this;
  }
  string ExtendedAddress::name() const {
    return rep_->name();
  }
  string ExtendedAddress::address() const {
    return rep_->address();
  }
  string ExtendedAddress::zip() const {
    return zip_;
  }
}
