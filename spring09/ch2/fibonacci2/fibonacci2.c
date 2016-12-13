/******************************************/
/* Programmer: Eric J Lima                */
/*                                        */
/* Program: Fibonacci of Order 2          */
/*                                        */
/* Time to complete: 10 minutes           */
/******************************************/

#include <stdio.h>

int fibonacci(int n){

   if(n == 1 || n == 2)
      return 1;
   else
      return (fibonacci(n - 1) + fibonacci(n - 2));
}

int main(int argc, char *argv[]){

   int n = atoi( argv[1] );

   printf("Fib(%d) = %d\n", n, fibonacci(n));
}
