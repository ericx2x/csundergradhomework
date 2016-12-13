/****************************************************/
/* main.cpp		     								*/
/*													*/		
/* Eric Lima										*/
/*													*/
/* October 29th, 2009								*/
/****************************************************/

#include <iostream>
#include "Clock.h"

using std::cout;
using std::endl;
using std::cin;

int main (int argc, char **argv) {

   Clock c1, c2, now;
   int h, m;
   
   now.setSysTime();
   cout << "The current time is ";
   now.printTime();
   cout << endl;
   
   cout << "Enter an hour (0-23) and minute (0-59)." << endl;
   cin >> h >> m;
   c1.setTime(h, m);

   c1.printTime();
   cout << "or ";
   c1.setFormat(24);
   c1.printTime();

   cout << "Enter another hour (0-23) and minute (0-59)." << endl;
   cin >> h >> m;
   c2.setTime(h, m);

   c2.printTime();
   cout << "or ";
   c2.setFormat(24);
   c2.printTime();
   c2.setFormat(12);

   cout << ((c1 < c2) ? "The second" : "The first") << " time you entered is later." << endl;
   
   return 0;
}
