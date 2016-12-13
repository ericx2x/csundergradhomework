#include <stdio.h>
#include "stack.h"
#include "globals.h"

#define SCREENMAX 100

static int screen[SCREENMAX][SCREENMAX] ;
static int xmax, ymax;

int init_image(filename)
     char *filename;
{
  
  FILE *fd = fopen(filename, "r");
  char linebuffer[BUFSIZ];
  int row, col;
  
  if (fd == NULL)
    return -1;

  fgets(linebuffer, BUFSIZ, fd);
  sscanf(linebuffer, "%d %d", &xmax, &ymax);
  if (xmax < 0 || ymax < 0) {
    fprintf(stderr, "Invalid image dimensions (%d,%d).\n", xmax, ymax);
    fclose(fd);
    return -1;
  }
  for (row = 0 ; row < xmax ; row++ ) {
    if (fgets(linebuffer, BUFSIZ, fd) == NULL) {
      fprintf( stderr, "Missing %d rows in data file\n", xmax - row ) ;
      break;
    }
    col = 0 ;
    while ( col < ymax ) {
      if (linebuffer[col] == '\n'){
	fprintf(stderr, "Missing %d columns on line %d.\n", ymax - col, row) ;
	for( ; col < ymax ; screen[row][col++] = 0 ) ;
      } else {
	screen[row][col] = linebuffer[col] - '0' ;
	col++;
      }
    }
  }
  xmax = row ; 
  fclose(fd) ;
  return 0 ;
}
int read_pixel(x, y)
     int x, y;
{
  
  if ( x < 0 || x >= xmax || y < 0 || y >= ymax )
    return -11 ;
  
  return screen[x][y] ;
}

int write_pixel(x, y, color)
     int x, y, color;
{
  if ( x < 0 || x >= xmax || y < 0 || y >= ymax ) 
    return -1 ;
  
  return screen [x][y] = color ;
}
void display_image()
{
  int row, col;
  printf("Dimensions: %d x %d\n", xmax, ymax) ;
  for (row = 0 ; row < xmax ; row++) { 
    printf("%3d ", row) ;
    for (col = 0 ; col < ymax ; col++ )
      printf("%1d", screen[row][col]) ;
    putchar('\n');
  }
  putchar('\n');
}
