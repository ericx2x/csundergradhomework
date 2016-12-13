/****************/
/* image.h      */
/****************/

#ifndef _image
#define _image

int init_image(char *filename);
int read_pixel(int x, int y);
int write_pixel(int x, int y, int color);
void display_image(void);

#endif
