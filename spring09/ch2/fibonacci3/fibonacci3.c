/******************************************************/
/* Programmer: Eric J Lima                            */
/*                                                    */
/* Program: Fibonacci of Order 3                      */
/*                                                    */
/* Time to complete: 52 minutes                       */
/******************************************************/

#include <stdio.h>

int fib_order_3( int n ){

   if(n <= 3 && n >= 1)
      return 1;
   
   else
      return fib_order_3(n - 1) + fib_order_3(n - 2) + fib_order_3(n - 3);
   
}


int main( int argc, char *argv[]){

   int n = atoi( argv[1] );

   if( n < 0 )
      printf("Input must be a positive integer.\n");

   else
      printf("The Fibonacci order 3 of %d is %d.\n", n, fib_order_3(n));

   return 0;
}
