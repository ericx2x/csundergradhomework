/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 60: File Comparison                                               */
/*                                                                           */
/* Approximate completion time: 44 minutes                                   */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){

  FILE *fin1, *fin2;
  
  fin1 = fopen( argv[1], "r") ;
  
  fin2 = fopen( argv[2], "r") ;
  
  int errcount = 0, current = 1, lines1 = 0,  lines2 = 0;
  
  char line1[101], line2[101];
  
  while (1){
    
    if ( fgets(line1, 101, fin1) != NULL ){

      lines1++;
    }
    
    else break;
    
    if ( fgets(line2, 101, fin2) != NULL ){      
      lines2++;
    }
    
    else break;

    if( strcmp(line1, line2) != 0){

      errcount++;

      printf("Difference in line %d.\n", current);
    }

    current++;

  }

  if (errcount == 0 && lines1 == lines2 ){

    printf("The files are identical.\n");

  }

  return 0 ;

}
