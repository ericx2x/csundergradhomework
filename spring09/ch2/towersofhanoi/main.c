/*******************************************************/
/* Programmer: Eric J Lima                             */
/*                                                     */
/* Program: Towers of Hanoi                            */
/*                                                     */
/* Approximate Completion Time:  34 minutes            */
/*******************************************************/


#include <stdio.h>
#include <stdlib.h>

void hanoi( char from, char to, char other, char n ) ;

int main() {
  
  int n ;
  
  printf("Input the number of disks: " ) ;
  scanf("%d", &n) ;
  if ( n <= 0 ) {
    printf("Illegal number\n");
    exit(-1);
  }
  else{
    hanoi('a','c','b', n);
    exit(0);
  }
}

void hanoi( char from, char to, char other, char n ) {
  if (n == 1 ) ;

  else{
    hanoi(from, other, to, n-1);
    hanoi(from, to, other, 1 ) ;
    hanoi(other, to, from, n-1) ;
  }
}
