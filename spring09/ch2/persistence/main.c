/*********************************************************/
/* Programmer: Eric J Lima                               */
/*                                                       */
/* Program: Recursive Persistence                        */
/*                                                       */
/* Approximate completion time: 53 minutes               */
/*********************************************************/

#include <stdio.h>

int persistence(int n);

int main(int argc, char *argv[]){

   int n;
   
   while(n != EOF){

      printf("Please enter a positive integer: ");
      scanf("%d", &n);

      printf("The persistence of %d is %d.\n", n, persistence(n));
   }

   return 0;
}

int persistence(int n){

   if (n < 10)
      return 0;
   
   else {

      int m = 1;

      while(n > 0){

         m *= (n % 10);
         n /= 10;
      }

      return 1 + persistence(m);
   }
}

