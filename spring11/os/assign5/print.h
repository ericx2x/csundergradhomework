#ifndef PRINT
#define PRINT

#define NUMBERENTRIES  (1001)
#define FALSE           (0)
#define TRUE            (1)
#define DONE            (2)

struct request {
  int isreg;
  int isallocated;
  int size;
  int baseadr;
  int nextboundaryadr;
  int memoryleft;
  int largestchunk;
  int elementsonfreelist;
} reqarray[NUMBERENTRIES];

struct freelist {
  struct freelist *next;
  struct freelist *prev;
  int blocksize;
  int blockadr;
  int adjacentadr;
} listhead, *top;

int totalfreespace;
int freelistlength;
int totalfree;
int allocatememory( struct request * );
int updatelist( int );

void printarray(struct request *reqarray, char *policy, int memsize);

#endif
