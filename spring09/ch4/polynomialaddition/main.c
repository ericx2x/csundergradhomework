/*****************************************************************************/
/* Polynomial Addition Program - main.c                                      */
/* Eric J Lima                                                               */
/* Last Modified January 30, 2009                                            */
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "polynomial.h"
#include "globals.h"

int main(int argc, char * argv[]) {
    /*
     * Read two polynomials, add them, and print the result.
     */
    polynomial poly1, poly2;

    printf("Enter the first polynomial:\n");
    if (read_poly(&poly1) == ERROR) {
        printf("Error in reading polynomial\n");
        exit(1);
    }

    printf("Enter the second polynomial:\n");
    if (read_poly(&poly2) == ERROR) {
        printf("Error in reading polynomial\n");
        exit(1);
    }

    if (!equal(poly1, poly2, equal_term)) { printf("These lists are different!\n"); }

    printf("  ");
    write_poly(poly1);
    printf("\n+ ");
    write_poly(poly2);

    if(add_poly(&poly1, &poly2) == ERROR) {
        printf("Error adding polynomials\n");
        exit(1);
    }

    printf("\n= ");
    write_poly(poly1);
    printf("\n");
    destroy_poly(&poly1);
    destroy_poly(&poly2);
    return OK; 
} 
