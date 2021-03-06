/***********************************************/
/* Programmer: Eric Lima                       */
/*								    */
/* File: mainsort  					    */
/*								    */
/* Date: February 25, 2011  			    */
/***********************************************/

#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler( int signal ){

  printf( "\n\n Child was killed and sigpipe was recieved.\n\n" ) ;
  printf( "Parent exit.. Cannot send data.\n\n" ) ;
}

int main( int argc, char *argv[] ) {
  
  FILE *datafile ;
  char buffer[81], print_buffer[100] ;
  pid_t pid ;  
  sigset_t mask ;
  struct sigaction newsigstate ;
  char lastname[50], firstname[50] ;
  int fd, pin[2], pout[2], nread, i, j, x, count = 0, tcount = 0 ;
  int areacode, oldcode, prefix, telnum, xcodecount = 0, totalcount = 0 ;

  sigemptyset( &mask ) ;
  newsigstate.sa_mask = mask ;
  newsigstate.sa_handler = sig_handler ;
  newsigstate.sa_flags = 0 ;

  if ( sigaction( SIGPIPE, &newsigstate, NULL ) == -1 ) 
    exit( 1 ) ;

  if( pipe( pin ) == -1 ){
    perror( "The first pipe call failed.\n" ) ;
    exit( 1 ) ;
  }

  if( pipe( pout ) == -1 ){
    perror( "The second pipe call failed.\n" ) ;
    exit( 1 ) ;
  }

  switch( pid = fork(  ) ){
    
    case 0:
      if(  close( 0 ) == -1 ){
        perror( "pipe" ) ;
        exit( 1 ) ;
      }
      if( dup( pout[0] ) != 0 ){
        perror( "dup" ) ;
        exit( 1 ) ;
      }
      if( close( 1 ) == -1 ){
        perror( "pipe" ) ;
        exit( 1 ) ;
      }
      if( dup( pin[1] ) != 1 ){
        perror( "dup" ) ;
        exit( 1 ) ;
      }
      if( close( pout[0] ) == -1 ||
         close( pout[1] ) == -1 ||
         close( pin[0] ) == -1  ||
         close( pin[1] ) == -1 ) 
      {
        perror( "close" ) ;
        exit( 1 ) ;
      }
    
    execlp( "sort", "sort", "-k", "3.3n", "-k", "1.1", "-k", "2.2", NULL  ) ;
    perror( "Failure occured in execlp"  ) ;
    exit( 1 ) ; 
  }
  
  if ( close(  pout[0] == -1 ) || close( pin[1] ) == -1 ){
    perror( "Close." ) ;
    exit( 1 ) ;
  }
  
  if ( ( x = open( "cs308a2_sort_data", O_RDONLY, 0 ) ) == -1 ){
    perror( "Can't open" ) ;
    exit( 1 ) ;
  }

  while ( ( nread = read( x, buffer, 80 ) ) ){

    if ( write( pout[1], buffer, nread ) == -1 ){
      exit( 1 ) ;
    }

    if ( ( count += nread ) < 4096 ){
      write( 1, "*", 1 ) ;
    }

    else{
      tcount += count ;
      count = 0 ;
      sprintf( print_buffer, "%d bytes sent\n", tcount ) ;
      write( 1, print_buffer, strlen( print_buffer ) +1 ) ;
    }
  } 

  write( 1, "\n\nData has been sent\n\n", 16 ) ;

  if ( close( pout[1] ) == -1 ){
    perror( "close" ) ;
    exit( 1 ) ;
  }

  datafile = fdopen( pin[0], "r" ) ;
  fscanf( datafile, "%s %s %d %d %d\n", lastname, firstname, &areacode, &prefix, &telnum ) ;
  printf( "First Line: %s %s %d %d %d\n", lastname, firstname, areacode, prefix, telnum ) ;
  xcodecount++ ;
  oldcode = areacode ;
  
  while( fscanf( datafile, "%s %s %d %d %d\n", lastname, firstname, &areacode, &prefix, &telnum ) != EOF ){

    if ( areacode != oldcode ){
      printf( "\n\nThe area code %d has occured %d number of times.\n", oldcode, xcodecount ) ;
      totalcount += xcodecount ;
      xcodecount = 1 ;
      oldcode = areacode ;
    }

    else{
      xcodecount++  ;
    }
  } 

  printf( "\n\nThe area code %d has occured %d number of times.\n\n", oldcode, xcodecount ) ;

  return 0 ;
}

