/*******************************************/
/* Programmer: Eric J Lima                 */
/*                                         */
/* Program: Insertion Sort                 */
/*                                         */
/* Time to complete: 46 minutes            */
/*******************************************/

#include <stdio.h>
#include <stdlib.h>

typedef enum { OK, ERROR } status;
status insertionsort(int A[], int n);

int main(int argc, char *argv[]){

   int A[500000];
   int i;
   int n;
   FILE *fin;

   fin = fopen(argv[1], "r");
   n = atoi(argv[2]);

   for(i = 0; i < n; i++) fscanf(fin, "%d", &A[i]);

   if(insertionsort(A, n) == ERROR) printf("Trouble sorting.\n");

   printf("The smallest number is: %d.\n", A[0]);
   printf("The middle number is: %d.\n", A[n/2]);
   printf("The largest number is: %d.\n", A[n-1]);

   fclose(fin);
   return 0;
}
status insertionsort(int A[], int n){

   int i, j, next ;

   for(i = 0; i < n; i++){

      next = A[i];
      j = i;

      while((j > 0) && (A[j-1] > next)){

         A[j] = A[j-1];
         j = j - 1;

      }

      A[j] = next;

   }

   return OK;
}
