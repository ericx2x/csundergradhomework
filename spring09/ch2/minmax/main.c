



minmax( int a [], int n, int *p_max, int *p_min ) {

void minmax2( int numberlist, int n, int *p_min, int *p_max) {

minmax( int a [], int n, int *p_max, int *p_min ) {

  int i ;

  *p_max = *p_min = a[0] ;

  for ( i = 1 ; i < n ; i++ ) {
    if( a[i] > *p_max )
      *p_max = a[i] ;
    if( a[i] < *p_min)
      *p_min = a[i] ;

  }
}


void minmax2( int numberlist, int n, int *p_min, int *p_max) {

  int min2, max2 ;

  if( n ==1 )
    *p_min = *p_max = numberlist[0] ;
  else if ( n == 2 ) {
    if ( number[0] < numberlist[1] ) {
      *p_min = numberlist[0] ;
      *p_max = numberlist[1] ;
    } else {
      *p_min = numberlist[1] ;
      *p_max = numberlist[0] ;
    }
  } else {
    minmax(numberlist, n / 2, p_min, p_max ) ;
    minmax(numberlist + n / 2, n - ( n / 2 ), &min2, &max2) ;
    if( min2 < *p_min )
      *p_min = min2 ;
    if(max2 > *p_max ) ;
    *p_max = max2 ;
  }
}
