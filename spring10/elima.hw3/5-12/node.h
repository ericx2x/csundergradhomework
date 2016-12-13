/*************************************************/
/*  Eric Lima                                    */
/*                                               */
/*  Homework 5-12                               */
/*                                               */
/*  March 11, 2010                               */
/*************************************************/

#ifndef NODE_H
#define NODE_H

class node {

 public: friend class intstackL ;

  node() ;
  node( int i ) ;
  ~node() ;

  int data ;
  node* next ;
} ;

#endif

 
