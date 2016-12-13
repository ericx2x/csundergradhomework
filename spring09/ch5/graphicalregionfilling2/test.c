/***************************************/
/* Programmer: Andrew MacRobert        */
/*                                     */
/* Program 19: Graphical Region Fill   */
/*                                     */
/* Completion Time: */
/***************************************/

#include <stdio.h>
#include "globals.h"
#include "stack.h"
#include "image.h"

#define INIT_ERR "Error initializing stack. Region not filled.\n"
#define PUSH_ERR "Error addinf to the stack. Region may not be totally filled.\n"
#define PUSH_XY(p_S, x, y) if(push_xy(p_S, x, y) == ERROR) { printf(PUSH_ERR); continue; }

void fill(int x, int y, int old_color, int new_color);

int main(int argc, char *argv[]) {

   char filename[BUFSIZ];
   int x, y, old_color, new_color;

   printf("Please enter the image's filename: ");
   scanf("%s", filename);

   if(init_image(filename) == -1) {
      printf("Error initializing the image.\n");
      exit(1);
   }

   display_image();

   fill(0, 0, read_pixel(0, 0), 4);

   display_image();
   
   return 0;
}


void fill(int x, int y, int old_color, int new_color) {

   stack S;

   if (init_stack(&S) == ERROR) {
      printf(INIT_ERR);
      return;
   }
   
   push_xy(&S, x, y);
   while (! empty_stack(&S)) {
      
      pop_xy(&S, &x, &y);

      if (read_pixel(x, y) == old_color) {

         write_pixel(x, y, new_color);
         PUSH_XY(&S, x, (y - 1));
         PUSH_XY(&S, x, (y + 1));
         PUSH_XY(&S, (x - 1), y);
         PUSH_XY(&S, (x + 1), y);
      }
   }
}

