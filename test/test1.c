
/* ************************************************************
 *    PROGRAM: Subtract Two Variables                    *
 *    WRITTEN BY: Chris Matses      *
 * COURSE NUMBER: 90:212                       *
 *       DATE: 9/23/10                           *
 *      FUNCTION: To subtract two variables from the user   *
 *          and display the results.                  *
 *                               *
 *                               *
 ************************************************************/

#include <stdio.h>

int main()


{

  /*************************************************************
   *     Define Variables:                   *
   ************************************************************/
  int A ; /* first number to be input by the user */
  int B ; /* second number to be input by the user */
  int result ; /* variable in which the remainder will be 
		 stored */




  /*************************************************************
   *Print Introduction to User                   *
   ************************************************************/
  printf(" Welcome to the Subtraction Program.\n");
  printf(" The user will be able to subtract one integer\n"); 
  printf("from another and obtain the result.\n");

  /*************************************************************
   *     Data Input Area                       *
   ************************************************************/
  printf(" Enter the first integer.\n ");
  scanf ("%d", &A);

  printf("Enter the second integer.\n ");
  scanf ("%d", &B);

  /*************************************************************
   *   Data Processing Area                   *
   ************************************************************/
  result= A-B;/* assign the remainder to result */

  /*************************************************************
   *     Data Output Area                   *
   ************************************************************/

  printf("The result is: %d", result);

  return 0; /*indicates the program ended successfully*/

}/* end function main */

