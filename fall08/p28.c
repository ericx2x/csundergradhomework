/******************************************************/
/* Programmer: Eric Joesph Lima                       */
/*                                                    */
/* Program 28: Persistence of a Number                */
/*                                                    */
/* Approximate completion time: 2 hours and 23 minutes*/
/******************************************************/

#include <stdio.h>

int persistence( int x ) ;

int main( int argc, char *argv[] ) {
  
  int x ;
  
  printf( "Please, enter a number or EOF.\nThis program will give you the persistence of the number you enter.\nTo quit enter EOF.\n" ) ;
  
  while( scanf( "%d" , &x ) != EOF) {
    
    printf( "The persistence of the number you entered is %d.\n" , persistence( x ) ) ;
    
  }
  
  return 0 ;
  
}

int persistence( int x ) {
  
  int digit, product = 1, count = 0 ;
  
  while( x >= 10 ) {
    
    while( x > 0 ) {
      
      digit = x % 10 ;
      
      x = x / 10 ;
      
      product = product * digit ;
      
    }
    
    x = product     ;
    
    product = 1     ;
    
    count++         ;
    
  }
  
 return count ;

}
