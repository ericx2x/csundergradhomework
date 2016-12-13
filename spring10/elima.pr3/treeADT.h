/*************************************************/
/*  Eric Lima                                    */
/*                                               */
/*  Project 3                                    */
/*                                               */
/*  April 27, 2010                               */
/*************************************************/

#ifndef _TREEADT
#define _TREEADT

#include "node.h"
#include "tree.h"

class treeADT : public treeImp {

  friend class Node ;

  public:

    treeADT( int ) ;
    treeADT() ;
    virtual ~treeADT() ;

    virtual Node& getRoot() ;

    virtual void add( int* ann, Node& n, Node& p, Node*m ) ;
    
    virtual void preorder() ;
    virtual void postorder() ;
    virtual void dfs() ;
    
    virtual int numberofnodes() ;
    virtual int height() ;
    virtual int leaves() ;
    
  private:

    Node** t ;
    int nodes_ ;

} ;

#endif
