/***************************************/
/* Eric Lima                           */
/*                                     */
/* Project 2                           */
/*                                     */
/* March 25, 2010                      */
/***************************************/

#include <iostream>
#include <string>
#include "tree.h"

using namespace std;

Tree::Tree( string s ) {

  Node* t = new Node( s );
  root = t;

}

Tree::Tree ( ) {

  root = NULL;

}

Tree::~Tree() { }

Node& Tree::getRoot ( ) {

  if ( root == NULL ) {
    cout << "Tree is empty." << endl;
    return *root;
  }

  else 
    return *root;
}
