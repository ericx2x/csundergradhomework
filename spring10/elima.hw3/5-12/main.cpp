/*************************************************/
/*  Eric Lima                                    */
/*                                               */
/*  Homework 5-12                                */
/*                                               */
/*  March 11, 2010                               */
/*************************************************/


#include "intstackL.h"
#include "intstackA.h"
#include <iostream>

using namespace std ;

int main( int argc, char *argv[] ) {

  cout << "An integer stack with an array of 3 integers is being made using the array approach" << endl ;

  IntStackA stackA(3) ;

  cout << "An integer stack with an array of 3 integers is being made using the linked list approach." << endl ;

  IntStackL stackB ;

  stackB.push(4) ;
  stackB.push(5) ;
  stackB.push(6) ;

  return 0 ;

}
