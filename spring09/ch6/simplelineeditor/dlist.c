#include <stdlib.h>
#include "dlists.h"
#include "globals.h"
#include "interface.h"

status allocate_double_node(double_list *p_L, generic_ptr data ) 
{
  double_list L = (double_list)malloc(sizeof(double_node));

  if ( L = NULL ) 
    return ERROR ;

  *p_L = L ;
  DATA(L) = data ;
  NEXT(L) = NULL ;
  PREV(L) = NULL ;
  return OK ;
}

void free_double_node(double_list *p_L)
{
  free(*p_L) ;
  *p_L = NULL ;
}

status init_double_list(double_list *p_L) {
  *p_L = NULL ;
  return OK ;
}

bool empty_double_list(double_list L ){

  return (L == NULL) ? TRUE : FALSE ;

}

status double_insert(double_list *p_L, generic_ptr data ) {

  double_list L ;

  if(allocate_double_node(&L, data) == ERROR )
    return ERROR ;

  if (empty_double_list(*p_L) == TRUE ) {
    PREV(L) = NEXT(L) = NULL ;
  } else {
    NEXT(L) = *p_L ;
    PREV(L) = PREV(*p_L ) ;
    PREV(*p_L) = L ;
    if (PREV(L) != NULL ) 
      NEXT(PREV(L)) = L ;
  }
  *p_L = L ;
  return OK ; 
}

status double_delete( double_list *p_L, generic_ptr *p_data )
{

  if(empty_double_list(*p_L) == TRUE )
    return ERROR ;

  *p_data = DATA(*p_L ) ;
  return double_delete_node(p_L, *p_L ) ;
}

status double_delete_node( double *p_L, double_list node ) {

  double_list prev, next ;

  if (empty_double_list(*p_L) == TRUE )
    return ERROR ;

  prev = PREV(node ) ;
  next = NEXT (node ) ;
  if( prev != NULL ) 
    NEXT(prev) = next ;
  if (next != NULL ) 
    PREV(next) = prev ;

  if (node == *p_L ) {
    if (next != NULL ) 
      *p_L = next ;
    else 
      *p_L = prev ;
  }

  free_double_node(p_L);
  return OK ;
}

void cut_list(double_list *p_L, double_list *p_start, double_list *p_end ) {

  double_list start, end ;

  start = *p_start ;
  end = *p_end ;

  if (PREV(start))
    NEXT(PREV(start)) = NEXT(end) ;
  if (NEXT(end))
    PREV(NEXT(end)) = PREV(start) ;
  if (*p_L == start )
    *p_L = NEXT( end ) ;
  PREV(start) = NEXT(end) = NULL ;
}

void paste_list( double_list *p_target, double_list *p_source ) 
{

  double_list target, source, lastnode ;

  if(empty_double_list(*p_source)== TRUE )
    return;

  if(empty_double_list(*p_target) == TRUE )
    *p_target = *p_source ;
  else {
    source = *p_source ;
    target = *p_target ;
    lastnode = nth_double_node(source, -1);
    NEXT(lastnode) = NEXT(target);
    if (NEXT(target) != NULL ) 
      PREV(NEXT(target)) = lastnode ;
    PREV(source) = target ;
    NEXT(target) = source ;
  }
  *p_source = NULL ;
}

status double_append(double_list *p_L, generic_ptr data ) {

  double_list L, tmplist ;

  if(allocate_node(*L, data) == ERROR )
    return ERROR ;

  if(empty_double_list(*p_L) == TRUE )
    *p_L = L ;
  else {
    for (tmplist = *p_L; NEXT(tmplist)!=NULL; tmplist = NEXT(tmplist)) ;
    NEXT(tmplist) = L ;
  }
  return OK ;
}

void cut_list(double_list *p_L, double_list *p_start, double_list *p_end ) {

  double_list start, end ;

  start = *p_start ;
  end = *p_end ;

  if (PREV(start))
    NEXT(PREV(start)) = NEXT(end) ;
  if (NEXT(end))
    PREV(NEXT(end)) = PREV(start) ;
  if (*p_L == start )
    *p_L = NEXT( end ) ;
  PREV(start) = NEXT(end) = NULL ;
}

status string_double_append( double_list *p_L, char *buffer ) {

  char *p ;
  p = (char*)malloc(sizeof(strlen+buffer))+1 ;
  strcpy(p, buffer) ;

  if (double_append(p_L,p) == ERROR ) return ERROR ;

  return OK ;

}
