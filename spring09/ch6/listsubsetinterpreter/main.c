list circ_list_iterator( list L, list lastreturn ) {

  if (lastreturn == NULL ) 
    return ( L ) ? NEXT( L ) : NULL ;
  else
    return (lastreturn == L ) ? NULL : NEXT(lastreturn) ;
}

int circ_length( list L )
{

  list lastreturn ;
  int length ;
  length = 0 ;
  lastreturn = NULL ;
  while ( ( lastreturn = circ_list_iterator( L, lastreturn )) != NULL ) length++;
  return length ;
}

list nth_node( list L , int number ) {

  list tmp; 

  if ( empty_circ_list(L) == TRUE ) return NULL ;

  if (number == -1 ) 
    return L ;

  tmp = L ;
  do {
    tmp = NEXT(tmp) ;
    number-- ;
  } while(number > 0 && tmp != L ) ;
  return (number != 0 ) ? NULL : tmp ;
}

status circ_traverse(list L, status (*p_func_f)() 
{

  list tmp ;

  if (empty_circ_list(L) == TRUE ) 
    return OK ;

  tmp = L ;
  do {
    tmp = NEXT(tmp) ;
    if ((*p_func_f)(DATA(tmp)) == ERROR ) 
      return ERROR ;
  } while (tmp != L ) ;
  return OK ;
}
