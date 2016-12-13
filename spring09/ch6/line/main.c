/*********************************************************************/
/* main.c                                                            */
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "globals.h"
#include "dlists.h"
#include "user.h"
#include "interface.h"

void printerror ( int errnum ) ;

int main ( int argc , char *argv[] ) {

  char filename[BUFSIZE] ;
  char buffer[BUFSIZE] ;

  double_list linelist, currentline ;
  bool file_edited, exit_flag ;
  int rc ;

  init_double_list ( &linelist ) ;
  printf("Enter the name of the file to edit: ");
  gets( filename ) ;

  if ( (rc = readfile ( filename, &linelist )) != 0 ) {

    printerror ( rc ) ;
    exit (1) ;

  }

  printf( "%d lines read.\n", double_length(linelist) ) ;
  currentline = nth_double_node(linelist, -1 ) ;
  file_edited = FALSE ;
  exit_flag   = FALSE ;

  while ( exit_flag == FALSE ) {

    printf("cmd: ") ;
    gets(buffer);

    switch (toupper (buffer[0] )) {

    case '\0': break;

    case 'P':
      rc = printlines( &buffer[1], &linelist, &currentline ) ;
      if ( rc ) printerror(rc);
      break;

    case 'D':
      file_edited = TRUE;
      rc = deletelines( &buffer[1], &linelist, &currentline) ;
      if ( rc ) printerror( rc );
      break;

    case 'I':
      file_edited = TRUE ;
      rc = insertlines( &buffer[1], &linelist, &currentline ) ;
      if ( rc ) printerror( rc );
      break;

    case 'M':
      file_edited = TRUE ;
      rc = movelines( &buffer[1], &linelist, &currentline ) ;
      if ( rc ) printerror ( rc ) ;
      break;

    case 'W':
      if ( buffer[1] != '\0' ) strcpy ( filename, &buffer[1] ) ;
      rc = writefile( filename, &linelist ) ;
      if ( rc != 0 ) printerror(rc) ;
      else printf("%d lines written\n", double_length(linelist));
      file_edited = FALSE ;
      break;

    case 'Q':

      if(file_edited == TRUE ){

	printf("File modified. Enter W to save, Q to discard. \n");
	file_edited = FALSE ;

      } else exit_flag = TRUE ;
      break;

    default: 

      printerror(E_BADCMD); 

      break;
    }
  }

  return ( 0 ) ;
}

void printerror ( int errnum ) {

  static char *errmsg[] = {

    "io error",
    "out of memory space",
    "invalid line specification",
    "invalid command",
    "error deleting lines"
  };

  if ( errnum < 0 || errnum >= MAXERROR ) {

    printf("System Error. Invalid error number: %d\n", errnum );
    return ;
  }
  printf("%s\n", errmsg[errnum - 1] );
}
