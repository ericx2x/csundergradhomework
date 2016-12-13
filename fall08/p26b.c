/***********************************************/
/* Programmer: Eric Joesph Lima                */
/*                                             */
/* Program 26: Bubble Sort                     */
/*                                             */
/* Approximate completion time: 39 minutes     */
/***********************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int i, j[10], k , a ; 
  FILE *fin           ;

  fin = fopen( argv[1] , "r" ) ;

  for( i = 0 ; i < 10 ; i++ )  fscanf( fin , "%d" , &j[i] ) ; 

   for( a = 0 ; a < 10 ; a++) { 
     for( i = 0 ; i < 9 ; i ++ ) 
       if( j[i] > j[i+1] ) {

	   k = j[i+1]    ;
	   j[i+1] = j[i] ; 
	   j[i] = k      ;
	 
       }  
   }

   for( i = 0 ; i < 10 ; i++ )  printf( "%d\n" , j[i] ) ;              

   fclose( fin ) ;

   return 0 ;

}
