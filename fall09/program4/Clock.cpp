/****************************************************/
/* Clock.cpp		         						*/
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


#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include "Clock.h"


Clock::Clock (int hour, int minut) {
   this -> format = 12;
   this -> m = AM;
   setTime (hour, minute);
}

void Clock::setTime (const int hour, const int minute) {
   this -> m = this -> AMorPM();
   this -> hour = hour % 24;
   this -> minute = minute % 60;
}

void Clock::setSysTime () {
   time_t seconds = time(NULL);
   struct tm *now = localtime(&seconds);
   this -> hour = (*now).tm_hour;
   this -> minute = (*now).tm_min;
}

void Clock::setFormat (const int format) {
   this -> format = format;
}

void Clock::getTime (int& hour, int& minute, DAYHALF& m){
   m = this -> AMorPM();
   this -> getTime (hour, minute);
}

void Clock::getTime (int& hour, int& minute) {
   hour = (this -> hour) % (this -> format);
   minute = this -> minute;
   if (this -> format == 12 && hour == 0) hour = 12;
}

void Clock::getTrueTime (int& hour, int& minute) {
   hour = this -> hour;
   minute = this -> minute;
}

void Clock::printTime () {
   int hour, minute;
   this -> getTime(hour, minute, m);

   std::cout << hour << ":" << std::setw(2) << std::setfill('0') << minute;
   if (this -> format == 12) std::cout << " " << DayHalfToString(m);
   std::cout << std::endl;
}

bool Clock::operator<(Clock& c2) {
   int c2hour, c2minute;
   c2.getTrueTime(c2hour, c2minute);

   int c1minSum, c2minSum;
   c1minSum = ((this -> hour) * 60) + this -> minute;
   c2minSum = (c2hour * 60) + c2minute;

   return (c1minSum > c2minSum) ? 0 : 1;
   
}

DAYHALF Clock::AMorPM() {
   return (this -> hour < 12) ? AM : PM;
}

std::string Clock::DayHalfToString(DAYHALF m) {
   return (m == AM ? "AM" : "PM");
}
