/*************************************************/
/*  Eric Lima                                    */
/*                                               */
/*  Homework 5-12                                */
/*                                               */
/*  March 11, 2010                               */
/*************************************************/

#include <iostream>
#include <string>
#include "intstackA.h"

// Polymorphic stack code is here.

using namespace std ;

IntStackA::IntStackA( int size ) {

  top_ = -1 ;
  size_ = size ;
  stack_ = new int[size] ;
}

IntStackA::IntStackA( const IntStackA& s ) {

  top_ = s.top_ ;
  size_ = s.size_ ;
  stack_ = new int[size_] ;

  for ( int i = 0 ; i <= top_ ; ++i )
    stack_[i] = s.stack_[i] ;
}

IntStackA& IntStackA::operator=( const IntStackA& s ) {

  if ( this == &s )
    return *this ;

  if ( size_ != s.size_ ) {
    delete [] stack_ ;
    stack_ = new int[s.size_] ;
  }

  top_ = s.top_ ;
  size_ = s.size_ ;

  for ( int i = 0 ; i <= top_ ; ++i )
    stack_[i] = s.stack_[i] ;

  return *this ;
}

IntStackA::~IntStackA() {

  delete [] stack_ ;
}

void IntStackA::push( int i ) {

  if ( top_ == size_ -1 )
    cout << "Stack Full " ;

  stack_[++top_] = i ;
}

int IntStackA::pop() {

  if( top_ == -1 )
    cout << "Stack Empty " ;

  return stack_[top_--] ;
}
