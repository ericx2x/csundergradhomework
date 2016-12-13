/***************************************/
/* Eric Lima                           */
/*                                     */
/* Project 2                           */
/*                                     */
/* March 25, 2010                      */
/***************************************/

#include <iostream>
#include <string>
#include "node.h"

using namespace std;

Node::Node ( string s ) {

  leftchild = NULL;
  rightchild = NULL;
  label = s;

}

Node::Node ( ) {

  leftchild = NULL;
  rightchild = NULL;
  label = "No Label was entered.";

}

Node::~Node () { }

Node& Node::next ( ) {

  if ( rightchild != NULL )
    return *rightchild;

  else {
    cout << "No right sibling entered." << endl;
    return *rightchild;
  }
}

Node& Node::getleftchild ( ) {

  if ( leftchild != NULL ) 
    return *leftchild;

  else {
    cout << "No left child entered." << endl;
    return *leftchild;
  }
}

Node& Node::insertLeft ( string s ) {

  Node *n = new Node( s );
  n->rightchild = leftchild;
  leftchild = n;

  return *leftchild;
}

Node& Node::insertRight ( string s ) {

  if ( rightchild != NULL )
    rightchild->insertRight( s );

  else {
    Node *n = new Node( s );
    rightchild = n; }

  return *rightchild;
}

void Node::dfs ( ) {

  cout << label << endl;
  
  if ( leftchild != NULL )
    leftchild->dfs();

  if ( rightchild != NULL ) 
    rightchild->dfs();

  return;
}
