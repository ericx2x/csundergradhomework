

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "ArrayHolder.h"
#include "Point.h"
#include "Rectangle.h"

// sets the width between grid rules. 0 turns this feature off.
const int GRIDSPACE = 10;

// the domain and range of the graph, must be > 0.
const int X_MAX = 30;
const int Y_MAX = 30;

ArrayHolder::ArrayHolder () {
   for (int i = 0; i < MAX; i++) {
      for (int j = 0; j < MAX; j++) {
         this -> a[i][j] = ' ';

         if ( GRIDSPACE > 0 && (i % GRIDSPACE == 0 || j % GRIDSPACE == 0))
            this -> a[i][j] = '.';
      }
   }
}

void ArrayHolder::getPoints() {
   
   double x, y;
   std::string input;
   std::cin.ignore(INT_MAX, '\n');

   while (getline (std::cin, input)) {
      
      if (input.empty())
         break;

      std::istringstream tmpisstream(input);
      tmpisstream >> x >> y;

      this -> addPoint(x, y);
   }

   this -> draw();
   
   return;
}

void ArrayHolder::getRect() {

   double x, y, width, length;

   std::cout << "Enter the x y coordinates of the top left corner." << std::endl;
   std::cin >> x >> y;
   std::cout << "Enter the width and length of the rectangle." << std::endl;
   std::cin >> width >> length;

   Point *pt = new Point (x, y);
   //Rectangle *rect = new Rectangle(pt, width, length);

   for (int i = (int)x; i < (int)width + (int)x - 1; i++){
      addPoint ((double)i, y);
      addPoint ((double)i, y - length + 1);
   }
   for (int i = (int)y; i > (int)y - (int)length; i--){
      addPoint (x, (double)i);
      addPoint (width + x - 1, (double)i);
   }

   this -> draw();
   
   return;
}

void ArrayHolder::addPoint(const double& x, const double& y) {

   if (!(x <= X_MAX && x >= 0 &&
       y <= Y_MAX && y >= 0)) return;
   
   Point *tmp;
   Point *newPoint = new Point (x, y);

   // insert new point into the front of the list
   tmp = this -> listpointer;
   this -> listpointer = newPoint;
   newPoint -> setNext (tmp);
   
   this -> a[(int)x][(int)y] = '*';
}

void ArrayHolder::draw() {

   for (int i = Y_MAX; i >= 0; i--) {
      std::cout << std::setw (2) << i << "|";

      for (int j = 0; j <= X_MAX; j++) {
         std::cout << this -> a[j][i] << " ";
      }

      std::cout << std::endl;
   }

   for (int i = 0; i < Y_MAX; i++) std::cout << "--";
   std::cout << "---" << std::endl << "  |";
   for (int i = 0; i < Y_MAX; i++)
      std::cout << std::setw (2) << std::left << i;
   std::cout << std::endl << std::endl;
   
   return;
}
