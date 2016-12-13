/*************************************/
/* Programmer: Eric Lima             */
/*                                   */
/* Program: Recursive Power          */
/*                                   */
/* Time to complete: 15 minutes      */
/*************************************/

#include <stdio.h>
#include <stdlib.h>

int power(int x, int n){
   if(n == 0)
      return 1;
   else
      return(x * power(x, n-1));
}

int main(int argc, char *argv[]){
   int x = atoi(argv[1]);
   int n = atoi(argv[2]);
   printf("%d raised to %d is %d.\n", x, n, power(x, n));
   
   return 0;
}
