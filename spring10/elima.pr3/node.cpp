/*************************************************/
/*  Eric Lima                                    */
/*                                               */
/*  Project 3                                    */
/*                                               */
/*  April 27, 2010                               */
/*************************************************/

#include <iostream>
#include <string>
#include "node.h"

using namespace std ;

Node::Node( int x ) {

  lc = NULL ;
  rs = NULL ;
  Label = x ;
}

Node::Node() {

  lc = NULL ;
  rs = NULL ;
  Label = 0 ;
}

Node::~Node() { }

Node& Node::next() {

  if ( rs != NULL )
    return *rs ;

  else {

    cout << "No right sibling." << endl ;
    return *rs ;
  }
}

Node& Node::getLc() {

  if ( lc != NULL ) 
    return *lc ;

  else {

    cout << "No left child." << endl ;
    return *lc ;
  }
}

Node& Node::insertLeft( int x ) {

  Node *n = new Node( x ) ;
  n->rs = lc ;
  lc = n ;

  return *lc ;
}

Node& Node::insertRight( int x ) {

  if ( rs != NULL )
    rs->insertRight( x ) ;

  else {

    Node *n = new Node( x ) ;
    rs = n ;
  }

  return *rs ;
}

void Node::printlabel() {

  cout << Label << endl ;
}
