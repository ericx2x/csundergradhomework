#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "circular.h"
#include "duck.h"
#include "ducksinterface.h"


int main (int argc, char *argv[]) {

   int i;
   int n, m;
   list ducks;
   duck *tempduck;
   
   init_circ_list (&ducks);
   
   printf("Input n and m: ");
   scanf("%d %d", &n, &m);
   printf("\n");

   printf("The circular list of ducks is: ");

   for (i = 1; i <= n; i++) {
      
      tempduck = (duck *) malloc(sizeof(duck));
      *tempduck = (duck) i;
      
      circ_append_duck (&ducks, tempduck);
   }

   printf("\nThe alligator ate the ducks in the following order: \n");

   ducks = NEXT(ducks);
   
   while (empty_circ_list (ducks) == FALSE)
      print_duck (getnextduck (&ducks, m));

   putchar('\n');
   
   return 0;
}
