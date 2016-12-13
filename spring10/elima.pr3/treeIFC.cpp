/*************************************************/
/*  Eric Lima                                    */
/*                                               */
/*  Project 3                                    */
/*                                               */
/*  April 27, 2010                               */
/*************************************************/

#include <iostream>
#include "treeIFC.h"

using namespace std ;

treeIFC::treeIFC( int s ) {

  Node* temp = new Node( s ) ;

  this->Root = temp ;

  temp->lc = 0 ;
  temp->rs = 0 ;
}

treeIFC::treeIFC() {

  Node* temp = new Node( 0 ) ;

  this->Root = temp ;

  temp->lc = 0 ;
  temp->rs = 0 ;

}

treeIFC::~treeIFC() {

  delete Root ;
}

Node& treeIFC::getRoot() {

  Node& temp = *(this->Root) ;

  return temp ;
}

void treeIFC::dfs() {

  Node* temp = &(this->getRoot()) ;

  cout << temp->Label << endl ;
  
  if ( temp->lc != NULL ) {

    treeIFC* temp2 = new treeIFC( temp->lc->Label ) ;
    temp2->Root = temp->lc ;
    temp2->dfs() ;
    delete temp2 ;
  }

  if ( temp->rs != NULL ) {

    treeIFC* temp3 = new treeIFC( temp->rs->Label ) ;
    temp3->Root = temp->rs ;
    temp3->dfs() ;
    delete temp3 ;   
  }   

  return ;
}

int treeIFC::numberofnodes() {

  return 0 ;

}

int treeIFC::height() {

  return 0 ;

}

int treeIFC::leaves() {

  return 0 ;

}

void treeIFC::add( int* ann, Node& n, Node& p, Node* m ) {

}

void treeIFC::preorder() {

}
void treeIFC::postorder() {

}



