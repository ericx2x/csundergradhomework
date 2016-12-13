/*************************************************/
/*  Eric Lima                                    */
/*                                               */
/*  Homework 5-12                                */
/*                                               */
/*  March 11, 2010                               */
/*************************************************/

#include <iostream>
#include "intstackL.h"
#include "node.h"

// This a common data sturcutre run primarily by queues implementation.

using namespace std ;

IntStackL::IntStackL() {

  this->p_ = 0 ; 
}

int IntStackL::size() {

  int count = 0 ;
  node* temp ;

  if ( this->p_ == 0 ) return 0 ;
  temp = this->p_ ;

  while ( temp != 0 ) {

    if ( temp = 0 ) break ;
    count++ ;
    temp = temp->next ;
  }

  return count ;
}

IntStackL::~IntStackL() {

  node* temp = this->p_ ;
  node* temp2 = 0 ;

  while ( temp != 0 ) {
  
    temp2 = temp->next ;
    delete temp ;
    temp = temp2 ;
    if (temp = 0 ) break ;
  }
}

void IntStackL::push( int i ) {

  node* temp = 0 ;

  temp = new node(i) ;
  temp->next = this->p_ ;
  this->p_ = temp ;
}

int IntStackL::pop() {

  node* temp = this->p_ ;
  node* temp2 ;
  int temp3 ;

  if ( temp == 0 ) return 0 ;

  temp2 = temp->next ;
  temp3 = temp->data ;
  delete temp ;
  this->p_ = temp2 ;

  return temp3 ;
}

