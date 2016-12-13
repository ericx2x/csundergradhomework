/*****************************************************/
/* Programmer: Eric Joesph Lima                      */
/*                                                   */
/* Program 68: Walsh Transform                       */
/*                                                   */
/* Approximate completion time: 1 hour 47  minutes   */
/*****************************************************/

#include <stdio.h>

void vectors( int vector[][8] ) ;

void walshmultiply( int vector[][8], int walsh[][8], float c[][8] );

void printsums( float c[][8]);

int main( int argc, char *argv[] ) {
  
  int walsh [8][8] = { { 1, 1, 1, 1, 1, 1, 1, 1 },
		       { 1, -1, 1, -1, 1, -1, 1, -1 },
		       { 1, 1, -1, -1, 1, 1, -1, -1 },
		       { 1, -1, -1, 1, 1, -1, -1, 1 },
		       { 1, 1, 1, 1, -1, -1, -1, -1 },
		       { 1, -1, 1, -1, -1, 1, -1, 1 },
		       { 1, 1, -1, -1, -1, -1, 1, 1 },
		       { 1, -1, -1, 1, -1, 1, -1, -1 }} ;
  
  int vector[5][8] ;
  
  float c[5][8] ;
  
  vectors( vector ) ;
  
  walshmultiply( vector, walsh, c ) ;
  
  printsums( c ) ;
  
  return 0 ;
  
}

void vectors( int vector[][8] ) {
  
  int i, j, n ;
  
  for( i = 0 ; i < 5 ; i++ ) 
    
    for( j = 0 ; j < 8 ; j++ ) {
     
      scanf( "%d", &n ) ;
      
      vector[i][j] = n ;
      
    }
  
}

void walshmultiply( int vector[][8], int walsh[][8], float c[][8] ) {
  
  int i, j, k ;
  
  float sum = 0 ;
  
  for( i = 0 ; i < 5 ; i++ ) {
    
    sum = 0 ; 

    for( j = 0 ; j < 8 ; j++ ) {
      
      for( k = 0 ; k < 8 ; k++ ) sum += (vector[i][k] * walsh[k][j]) ; 
      
      c[i][j] = sum / 8 ;
            
    }
    
  }
  
}

void printsums( float c[][8] ) {

  int i, j ;
  
  printf( "\n" ) ;
  
  for( i = 0 ; i < 5 ; i++ ) {
    
    for( j = 0 ; j < 8 ; j++ ) printf( "%g  ", c[i][j] ) ;
    
    printf( "\n\n" ) ;
    
  }
  
}
