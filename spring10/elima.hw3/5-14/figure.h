/*************************************************/
/*  Eric Lima                                    */
/*                                               */
/*  Homework 5-14                                */
/*                                               */
/*  March 11, 2010                               */
/*************************************************/

class Figure {
 private:

 public:
  void draw();
  void moveTo( int, int );

};

class Point: public Figure {
 public:

 private:
  int x, y;

};
