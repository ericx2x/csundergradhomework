  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 5.6
  // Interface for class ExtendedAddress
  // File: e5.6-address-extended.h
#ifndef E5_6_ADDRESS_EXTENDED_H
#define E5_6_ADDRESS_EXTENDED_H 
#include <string>
#include "e5.6-address.h"
namespace e56 {
class ExtendedAddress {
public:
  ExtendedAddress(const string&, const string&, const string&);//a contructor that takes 3 args, which are all references to strings. 
  ExtendedAddress(const ExtendedAddress&);//a copy constructor. 
  virtual ~ExtendedAddress();//a desructor which uses the canonical construction idiom.
  ExtendedAddress& operator=(const ExtendedAddress&);//overload assignment opperator.
  
  string name() const;
  string address() const;
  string zip() const;
private:
  Address* rep_;
  string zip_;
};
}
#endif
