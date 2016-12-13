/**************************************/
/* Programmer: Eric Lima              */
/*                                    */
/* Program: Recursive Factorial       */
/*                                    */
/* Time to copmlete: 40 minutes       */
/**************************************/

#include <stdio.h>
#include <stdlib.h>

int factorial(int n){
   if(n == 0)
      return 1;
   else
      return n * factorial(n - 1);
}

int main(int argc, char *argv[]){
   int num = atoi(argv[1]);
   printf("The factorial of %d is %d.\n", num, factorial(num));
   
   return 0;
}
