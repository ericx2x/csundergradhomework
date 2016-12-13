/***********************************************************************/
/* Programmer: Eric Joesph Lima                                        */
/*                                                                     */
/* Program 44: Malloc up Space for a 1 Dimensional Array of n Integers */
/*                                                                     */
/* Approximate completion time: 46 minutes                             */
/***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

int arraysum( int x[], int n ) ;
int main( int argc, char *argv[] ) {

  int n ;

  int *x = ( int* )malloc( sizeof( int ) *n ) ;
  
  printf( "Please, enter in the number of times you want to enter numbers into the array. \n" ) ;
  
  scanf( "%d", &n ) ;
  
  printf( "The sum of the numbers you have entered is %d. \n", arraysum( x, n ) );
  
  return 0 ;
  
}

int arraysum( int x[], int n) {  

  int  sum = 0 ;

  int i ;
  
  printf( "Enter %d numbers into the array. \n" , n ) ;

  for( i = 0 ; i < n ; i++ ) {
    
    scanf( "%d", &x[i] ) ;

    sum += x[i] ;
   
  }
 
  return sum ;

}
