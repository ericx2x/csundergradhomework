  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 5.6
  // Interface for class Address
  // File: e5.6-address.h
  
#ifndef E5_6_ADDRESS_H
#define E5_6_ADDRESS_H 
#include <string>

  // The Address class is declared here as well as private members and public 
  // variables. This is a function that registers the name and address fields. 
 // The constructor recieves a value and creates an unique variable.

namespace e56 {
class Address {
public:
  Address(const string&, const string&);//contructor that takes two references to string.
  string name() const;//a query function which returns name.
  string address() const;//a query function that returns the address.
private:
  string name_;
  string address_;
};
}
#endif
