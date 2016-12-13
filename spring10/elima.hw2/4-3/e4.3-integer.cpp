  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex4.3.integer.cpp
  // Implementation of operations for the integer wrapper class
 #include "e4.3-integer.h"

/*  Here all private and protected functions return objects.
This gives control when creating all the objects. 
Wrapper function is useful for this.
*/


// Homework assignment says to comment on each member function of this file so I will...

 Integer::Integer(int i) : value_(i) {}
 Integer Integer::make(int i) { 
   return Integer(i);  // returns a object
 }
 int Integer::get() const { 
   return value_;         //function returns a object _value
 }
 Integer& Integer::set(int n) {
    value_ = n;          //sets value_ equal to n
    return *this;        //function returns a object
  }
  Integer& Integer::plus(int i) {
    value_ += i;         // value is increased by i
    return *this;        // function returns a object *this
  }  
  Integer& Integer::plus(const Integer& i) {
    value_ += i.value_;  // value is increased by i.value_
    return *this;        // function returns a object *this
  }
  Integer& Integer::minus(int i) {
    value_ -= i;         //value is decreased by i
    return *this;        //returns a object
  }     
  Integer& Integer::minus(const Integer& i) {
    value_ -= i.value_;  // value_ is dereased by i.value_
    return *this;        //function returns a object *this
  }  
  Integer Integer::times(const Integer& i) const {
    return Integer(value_*i.value_);        //function returns a object Integer(value_ *i.value_)
  }  
  Integer Integer::times(int i) const {
    return Integer(i*value_);         //function returns a object Integer(i*value_)
  }    
  Integer Integer::divide(const Integer& i) const throw(std::domain_error) {
    if(i.value_ == 0) throw(std::domain_error("can't divide by 0")); //checks if its equal to 0 and sets error if true.
     return Integer(value_/i.value_);          //function returns a object Integer(value_/i.value_)
  }  
  Integer Integer::divide(int i) const throw(std::domain_error) {
    if(i == 0) throw(std::domain_error("can't divide by 0"));  //checks to see if value is equal to 0 and sets error if true.
    return Integer(value_/i);                 //function returns a object Integer(value_/i.value_)
  }    
  Integer Integer::clone() const {
    return Integer(value_);        //function returns a object Integer(value_)
  }

