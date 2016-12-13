#include <stdio.h>
#include <sys/time.h>

int main()
{
   struct timeval tv;
   double secs;
   double usecs;
   gettimeofday(&tv,0);
   secs=tv.tv_sec;
   usecs=tv.tv_usec;
   printf("%lf\n", secs);
   printf("%lf\n", usecs);
   printf("%lf\n",secs*1000+usecs/1000);
}
