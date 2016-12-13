/*************************************************/
/*  Eric Lima                                    */
/*                                               */
/*  Project 3                                    */
/*                                               */
/*  April 27, 2010                               */
/*************************************************/

#ifndef _TREEIFC
#define _TREEIFC

#include "tree.h"
#include "node.h"

class treeIFC : public treeImp {

  friend class Node ;

  public:

    treeIFC( int ) ;
    treeIFC() ;
    virtual ~treeIFC() ;

    virtual Node& getRoot() ;

    virtual void add( int* ann, Node& n, Node& p, Node* m ) ;

    virtual void preorder() ;
    virtual void postorder() ;
    virtual void dfs() ;
    
    virtual int numberofnodes() ;
    virtual int height() ;
    virtual int leaves() ;
    
  private:

    Node* Root ;
    int nodes_ ;

} ;

#endif
