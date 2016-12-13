

#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "polynomial.h"

int main(int argc, char *argv[]){

   /* Read two polynomials, add them, and print the result. */

   polynomial poly1, poly2;

   printf("Enter the first polynomial:\n");
   if(read_poly(&poly1) == ERROR){
      printf("Error reading polynomial.\n");
      exit(1);
   }
   
   printf("Enter the second polynomial:\n");
   if(read_poly(&poly2) == ERROR){
      printf("Error reading polynomial.\n");
      exit(1);
   }


   printf("  ");
   write_poly(poly1);
   printf("\n+ ");
   write_poly(poly2);

   if(add_poly(&poly1, &poly2) == ERROR){
      printf("Error adding polynomials.\n");
      exit(1);
   }
   
   printf("\n= ");
   write_poly(poly1);
   printf("\n");

   destroy_poly(&poly1);
   destroy_poly(&poly2);

   return 0;
}
