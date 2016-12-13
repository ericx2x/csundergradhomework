/*************************************************/
/*  Eric Lima                                    */
/*                                               */
/*  Project 3                                    */
/*                                               */
/*  April 27, 2010                               */
/*************************************************/

#ifndef _TREE
#define _TREE

#include "node.h"

// This uses a bridge design pattern. Depending on the client's choice this will call the correct implementation. 

class treeImp {

 public:
    
  virtual Node& getRoot()= 0 ;    

  virtual void add( int* ann, Node& n, Node& p, Node*m ) = 0 ;
    
  virtual void preorder() = 0 ;
  virtual void postorder() = 0 ;
  virtual void dfs() = 0 ;
    
  virtual int numberofnodes() = 0 ;
  virtual int height() = 0 ;
  virtual int leaves() = 0 ;

} ;
  
class Tree {

 public:

  Tree( int, int ) ;
  Tree( int ) ;
  Tree() ;
  ~Tree() ;

  Node& getRoot() ;

  void add( int* ann, Node& n, Node& p, Node*m ) ;
    
  void preorder() ;
  void postorder() ;
  void dfs() ;
    
  int numberofnodes() ;
  int height() ;
  int leaves() ;
    
 private:

  treeImp* treeObject_ ;
  int nodes_ ;

} ;

#endif
