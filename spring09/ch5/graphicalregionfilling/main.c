#include <stdio.h>
#include "image.h"
#include "stack.h"
#include "globals.h"


main(int argc, char *argv[]) {
  
  char filename[BUFSIZ] ;
  int x, y, old_color, new_color ;
  
  printf(" Enter image file name: ") ;
  scanf("%s", filename ) ;
  if (init_image(filename == -1 )) {
    printf("Error initializing the image.\n") ;
    exit(1);
  }
  while(TRUE) {
    display_image();
    printf("Enter the point at which the fill should start (x, y): ");
    scanf("%d, %d", &x, &y ) ;
    if ( x == -1 && y == -1 )
	  break ;
    old_color = read_pixel( x, y ) ;
    do {
      printf("Pixel color is %d. Enter the new color: ", old_color ) ;
      scanf("%d", &new_color ) ;
    } while (old_color == new_color || new_color < 0 || new_color > 9 ) ;
    fill( x, y, old_color, new_color ) ;
  }
  printf("All done.\n");
}
