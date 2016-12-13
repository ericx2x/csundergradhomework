#ifndef POINT
#define POINT

class Point {

   public:
      Point (double x, double y);
      double& getX(double& x);
      double& getY(double& y);
      void setNext (Point *next);
      
   private:
      double x, y;
      Point *next;

};

#endif
