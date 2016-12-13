#include <stdio.h>
#include <globals.h>

status push_xy(stack *p_S, int x, int y);
status pop_xy(stack *p_S, int *p_x, int *p_y);

#define INIT_ERR
#define PUSH_ERR
#define PUSH_XY(p_S, x, y)
if (push_xy(p_S, x, y) == ERROR ) {
  printf(PUSH_ERR);
  continue;
}

void fill(x, y, old_color, new_color)
     int x, y, old_color, new_color;
{

  stack S;

  if(init_stack(&S) == ERROR) {
    printf(INIT_ERR);
    return;
  }
  push_xy(&S, x, y);
  while(! empty_stack(&S)){
    pop_xy(&S, &x, &y);
    if(read_pixel(x, y) == old_color){
      write_pixel(x, y, new_color);
      push_xy(&S, x, y - 1) ;
      push_xy(&S, x, y + 1) ;
      push_xy(&S, x - 1, y) ;
      push_xy(&S, x + 1, y) ;
    }
  }
}
