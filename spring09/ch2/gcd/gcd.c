/***************************************/
/* Programmer: Eric Lima               */
/*                                     */
/* Program: Recursive GCD              */
/*                                     */
/* Time to complete: 15 mins           */
/***************************************/

#include <stdio.h>

int gcd(int n, int m){
   if(n < m)
      return gcd(m, n);
   else if(n >= m && n % m ==0)
      return m;
   else
      return gcd(m, n % m);
}

int main(int argc, char *argv[]){
   int m, n;

   printf("Please input two positive integers.\n");
   scanf("%d %d", &m, &n);

   printf("The Greatest Common Denominator is %d.\n", gcd(n, m));

   return 0;
}
