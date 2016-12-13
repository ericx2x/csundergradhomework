/***********************************/
/* heap.c                          */
/***********************************/

#include "globals.h"
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

static void siftdown ( heap *p_H, int parent, int (*p_cmp_f)() ) ;
static void siftup ( heap *p_H, int element, int (*p_cmp_f)() );

extern status init_heap ( heap *p_H) {

  p_H -> base = (generic_ptr *) malloc(HEAPINCREMENT*sizeof(generic_ptr)) ;

  if ( p_H -> base == NULL ) return ERROR ;

  p_H -> nextelement = 0 ;
  p_H -> heapsize = HEAPINCREMENT ;
  return OK;

}

extern bool empty_heap ( heap *p_H ) {  return ( p_H -> nextelement == 0 ? TRUE : FALSE ); }

extern status heap_insert( heap *p_H, generic_ptr data, int (*p_cmp_f)() ) {

  if ( p_H -> nextelement == p_H -> heapsize ) {

    generic_ptr *newbase = (generic_ptr *) realloc(p_H -> base, (p_H->heapsize+HEAPINCREMENT)*sizeof(generic_ptr));
    if (newbase == NULL ) return ERROR ;
    p_H -> base = newbase ;
    p_H -> heapsize += HEAPINCREMENT ;   

  }
  p_H -> base[p_H -> nextelement] = data ;
  siftup(p_H, p_H -> nextelement, p_cmp_f );
  p_H -> nextelement++ ;
  return OK ;

}

extern void siftup( heap *p_H, int element, int (*p_cmp_f)() ) {

  int parent ;
  int cmp_result;
  generic_ptr tmpvalue ;

  if ( element == 0 ) return ;

  parent = (element - 1)/2;
  cmp_result = (*p_cmp_f)(p_H -> base[element], p_H -> base[parent] );
  if (cmp_result >= 0 ) return ;

  tmpvalue = p_H -> base[element] ;
  p_H -> base[element] = p_H -> base[parent] ;
  p_H -> base[parent] = tmpvalue ;
  siftup(p_H, parent, p_cmp_f );

  return;

}

extern status heap_delete( heap *p_H, int element, generic_ptr *p_data, int (*p_cmp_f)() ){

  if ( element >= p_H -> nextelement ) return ERROR ;

  *p_data = p_H -> base[element] ;
  p_H -> nextelement-- ;
  if ( element != p_H -> nextelement ) {

    p_H -> base[element] = p_H -> base[p_H -> nextelement ] ;
    siftdown(p_H, element, p_cmp_f );

  }
  return OK ;

}

static void siftdown ( heap *p_H, int parent, int (*p_cmp_f)() ) {

  int leftchild, rightchild, swapelement;
  int leftcmp, rightcmp, leftrightcmp ;
  generic_ptr tmpvalue ;

  leftchild = 2 * parent + 1 ;
  rightchild = leftchild + 1 ;

  if ( leftchild >= p_H -> nextelement ) return ;

  leftcmp = (*p_cmp_f)(p_H -> base[parent], p_H -> base[leftchild] ) ;
  if ( rightchild >= p_H -> nextelement ) {

    if ( leftcmp > 0 ) {

      tmpvalue = p_H -> base[parent] ;
      p_H -> base[parent] = p_H -> base[leftchild] ;
      p_H -> base[leftchild] = tmpvalue ;

    }
    return ;

  }
  rightcmp = (*p_cmp_f)(p_H -> base[parent], p_H -> base[rightchild] );
  if ( leftcmp > 0 || rightcmp > 0 ) {

    leftrightcmp = (*p_cmp_f)(p_H -> base[leftchild], p_H -> base[rightchild] );
    swapelement =(leftrightcmp < 0 ) ? leftchild : rightchild;
    tmpvalue = p_H -> base[parent] ;
    p_H -> base[parent] = p_H -> base[swapelement];
    p_H -> base[swapelement] = tmpvalue ;
    siftdown( p_H, swapelement, p_cmp_f );

  }
  return ;

}
				
