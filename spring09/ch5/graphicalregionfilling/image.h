#include <stdio.h>
#include "stack.h"
#include "globals.h"

#define SCREENMAX 100

static int screen[SCREENMAX][SCREENMAX] ;
static int xmax, ymax ;

int init_image(char *filename) ;

int read_pixel(int x,int y) ;

int write_pixel(int x,int y, int color) ;

void display_image() ; 
