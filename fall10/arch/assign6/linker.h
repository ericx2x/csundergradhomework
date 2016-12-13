/********************************/
/* Eric Lima                    */
/*                              */
/* linker.c                     */
/*                              */
/* December 1st, 2010           */
/********************************/

#ifndef _LINKER
#define _LINKER

typedef struct list
{
	char *label;
	int value;
	struct list *next;
} List;


int readFile (FILE* in, FILE* temp1, List** list, int* pc);
int printFile (FILE* in);
int find_val (char* label, List* list);
FILE* refine (FILE* temp1, List* list);
char* decbin(int n);
int bindec(char* in);
	
#endif
