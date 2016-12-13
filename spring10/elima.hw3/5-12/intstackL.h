/*************************************************/
/*  Eric Lima                                    */
/*                                               */
/*  Homework 5-12                                */
/*                                               */
/*  March 11, 2010                               */
/*************************************************/

#ifndef STACKL_H
#define STACKL_H

#include "node.h"

//The linked list approach is here.

class IntStackL {

 public:

  IntStackL() ; 
  ~IntStackL() ;

  void push( int i ) ; // Integer is pushed on a queue here.
  
  int pop() ; // Integer is deleted on a queue here.

  int size() ; // This gets the size of the list.

  node* p_ ;

} ;

#endif
