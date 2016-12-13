/*************************************************/
/*  Eric Lima                                    */
/*                                               */
/*  Project 3                                    */
/*                                               */
/*  April 27, 2010                               */
/*************************************************/
#include <iostream>
#include <string>
#include "treeADT.h"

using namespace std ;

treeADT::treeADT( int size ) {

  int i ;

  Node** temp = new Node*[size] ;
  t = temp ;

  Node* rtemp = new Node( 0 ) ;
  t[0] = rtemp ;
  
  for ( i = 1; i < size; i++ ) {

    Node* n = new Node( i ) ;
    t[i] = n ;

    if ( i != size-1 ) 
      t[i]->rs = t[i+1] ;    
  }  
  
  if ( size > 1 )
    t[0]->lc = t[1] ;

  nodes_ = size ;  
}

treeADT::treeADT() {

  int size = 10 ;
  int i ;

  Node** temp = new Node*[size] ;
  t = temp ;

  Node* rtemp = new Node( 0 ) ;
  t[0] = rtemp ;
  
  for ( i = 1; i < size; i++ ) {

    Node* n = new Node ( i ) ;
    t[i] = n ;

    if ( i != size-1 ) 
      *t[i]->rs = *t[i+1] ;    
  }  
  
  if ( size > 1 )
    *t[0]->lc = *t[1] ;

  nodes_ = size ;  
}  

treeADT::~treeADT() { 

  delete [] t ;

}

Node& treeADT::getRoot() {

  return *t[0] ;
}

int treeADT::numberofnodes() {

  return nodes_ ;
}

int treeADT::leaves() {
    
  return 0 ;
}

void treeADT::add( int* ann, Node& n, Node& p, Node*m ) { 

  if (  &n.getLc() == NULL ) {
    p.insertLeft( *ann ) ;
  }

  else   
    n.insertRight( *ann ) ; 

  nodes_++ ; 

}

void treeADT::preorder() {

}

void treeADT::postorder() {

}

int treeADT::height() {

  return 0 ;

}

void treeADT::dfs() {

}
