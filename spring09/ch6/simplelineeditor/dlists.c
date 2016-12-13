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
