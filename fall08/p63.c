/*****************************************************************************/
/* Programmer: Eric Joesph Lima                                              */
/*                                                                           */
/* Program 63: Cube Crawling                                                 */
/*                                                                           */
/* Approximate completion time: 5 hours                                      */
/*****************************************************************************/

#include <stdio.h>

void Punisher(int *x, int *y, int *z, char dir, char coord, int n, int L) {
  /*change xyz coordinatnes to new position*/
  /* p is a pointer to the coord being acted upon */
  /* wrap_dir/coord specify +/- & x/y/z  if wrap around ocurs */
  int *p;
  char movedir, movecoord;
  
  switch(coord){
    
  case 'x':
    p = x ;
    
    if(*y == 0 ) {
      movedir = '+' ;
      movecoord = 'y' ;
    }
    else if (*y == L ) {
      movedir = '-';
      movecoord = 'y' ;
    }
    else if(*z == 0 ) {
      movedir = '+' ;
      movecoord = 'z' ;
    }
    else if (*z == L ) {
      movedir = '-';
      movecoord = 'z' ;
    }
    else{
      printf("Not possible.\n");
      return;
    }
    break;
    
  case 'y':
    p = y ;
    
    if(*x == 0 ) {
      movedir = '+' ;
      movecoord = 'x' ;
    }
    else if (*x == L ) {
      movedir = '-';
      movecoord = 'x' ;
    }
    else if(*z == 0 ) {
      movedir = '+' ;
      movecoord = 'z' ;
    }
    else if (*z == L ) {
      movedir = '-';
      movecoord = 'z' ;
    }
    else{
      printf("Not possible.\n");
      return ;
    }
    break ;
    
  case 'z':
    p = z ;
    
    if(*x == 0 ) {
      movedir = '+' ;
      movecoord = 'x' ;
    }
    else if (*x == L ) {
      movedir = '-';
      movecoord = 'x' ;
    }
    else if(*y == 0 ) {
      movedir = '+' ;
      movecoord = 'y' ;
    }
    else if (*y == L ) {
      movedir = '-';
      movecoord = 'y' ;
    }
    else{
      printf("Not possible.\n");
      return;
    }
    break;
  default: 
    printf("Error - Invalid input.\n");
    return;
  }

  if( dir == '-' ) {
    if(*p - n < 0 ) {
      n -= *p ;
      *p = 0 ;
      Punisher ( x, y, z, movedir, movecoord, n, L ) ;
    }
    else *p -= n ;
  }
  else {
    
    if (n + *p > L) {
      n -= (L - *p) ;
      *p = L;
      Punisher (x, y, z, movedir, movecoord, n, L ) ;
    }
    else *p += n ;
  }
  return ;
}

int main( int argc, char *argv[] ) {
  int L, x, y, z, n ;
  char dir, coord;
  
  printf("Please, enter in the length of the cube. ");

    scanf("%d", &L ) ;
    x=L;
    z=L;
    L=L*2;
    y=L;

  printf("\nEnter in a line of input that will contain three values: a direction(+/-), an axis (x,y, or z) and a positive integer representing the distance to travel in that direction. The final line of input will be a single '.' character. ");

    do {
      scanf("%c", &dir ) ;
      if (dir == '-' || dir == '+' ) {
	scanf("%c %d", &coord, &n ) ;
	Punisher( &x, &y, &z, dir, coord, n, L);
      
    }
  } while(dir!='.');
  
  printf("\n%d %d %d\n", x, y, z ) ;
  
  return 0 ;
  }
