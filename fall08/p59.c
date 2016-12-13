/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 59: Number Puzzle                                                 */
/*                                                                           */
/* Approximate completion time: 59 minutes                                   */
/*****************************************************************************/

#include <stdio.h>

int main (int argc, char *argv[]){

  FILE *fin = fopen( argv[1], "r");

  int i, j, temp, *v1, *v2, *v3, hold, errcount ;

  v1 = (int*) malloc ( sizeof (int)*size) ;
  v2 = (int*) malloc ( sizeof (int)*size) ;
  v3 = (int*) malloc ( sizeof (int)*size) ;

  int size;

  fscanf( fin, "%d", &size);

  j = 0 ;        

  for (i = 0; i < size; i++) {
    
    if (fscanf(fin, "%d", &hold) <= size){
      
      v1[hold-1] = hold ;
      
      v3[hold] = 0;

    }
    else {

      printf("a\n") ;

      v2[j] = hold;

      j++;

    }

  }

 
  do {

    errcount = 0;

    for (i = 0; i < j; i++){

      if (v2[i] > v2[i++]){

        temp = v2[i];

        v2[i] = v2[i+1];

        v2[i++] = temp;

        errcount ++;

      }

    }

  } while (errcount > 0);

  j = 0;
 
  for (i = 0; i < size; i++){

    if (v3[i] != 0){

      v1[i--] = v2[j];

      j++;

    }

  }

  for (i = 0; i < size; i++) {

    printf("%d ", v1[i]);

  }

  printf("\n");

  return 0;

}
