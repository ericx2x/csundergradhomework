/****************************************************/
/* Clock.h   		         						*/
/*													*/		
/* Eric Lima										*/
/*													*/
/* October 29th, 2009								*/
/****************************************************/

#ifndef CLOCK
#define CLOCK

#include <string>

typedef enum { AM, PM } DAYHALF;

class Clock {
   public:

      Clock (int hour = 0, int minute = 0);
      void setTime (const int hour, const int minute);
      void setSysTime ();
      void setFormat (const int format);
      void getTime (int& hour, int& minute, DAYHALF& m);
      void getTime (int& hour, int& minute);
      void getTrueTime (int&hour, int&minute);
      void printTime ();
      bool operator<(Clock& c2);

   private:

      int hour, minute;
      int format;
      DAYHALF m;

      DAYHALF AMorPM();
      std::string DayHalfToString(DAYHALF m);
};

#endif
