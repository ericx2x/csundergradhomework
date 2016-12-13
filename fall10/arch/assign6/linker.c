/********************************/
/* Eric Lima                    */
/*                              */
/* linker.c                     */
/*                              */
/* December 1st, 2010           */
/********************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "linker.h"

int main(int argc, char* argv[])
{

    int i;
    int pc = 0;
    int option = 0;
    FILE *temp1;
    FILE *file;
    List *list = NULL;
    char* tempstr;
		
    if (argc > 1)
	{
	  if (!strcmp(argv[1], "-o"))
			option = 1;
	} else {
		printf("Use -o please. \n\n");
        return 0;   
	}

    temp1 = fopen("temp.tlf", "w+");
    unlink("temp.tlf");
	
	if(option)
		i = 2;
	else
		i = 1;
	
    while (i < argc)
    {
		file = fopen(argv[i], "r");
		if (file == NULL)
		{
			printf("ERROR\n\n", argv[i]);
			return 0;
		}
		
		readFile(file, temp1, &list, &pc);
        
        fclose(file);
	i++;
    }
	
	if (option)
	{
		if (list != NULL)
		  fprintf(temp1, " %s\n", "4096 x");
		
		while (list != NULL)
		{
			
		  fprintf(temp1, "   %s %d\n", list->label, list->value);
		  list = list->next;
			
		}    
		printFile(temp1);
	
	} else {
				
		temp1 = refine(temp1, list);
		printFile(temp1);
	}
	
    fclose(temp1);
    return 0;

}

int readFile(FILE *in, FILE *temp1, List **list, int *pc)
{
	int currentPc;
	int labelExists = 0;
	int tval;
	int tpc;
	
	char temp[50];
	char temp2[50];
	char *test = NULL;

	List *tlist;
	
	while (1)
	{
		labelExists = 0;
		if (fscanf(in, "%d", &currentPc) == EOF)
			break;
		
		if (currentPc == 4096)
		{
			if (fscanf(in, "%s", &temp) == EOF)
				break;
			while (fscanf(in, "%s %d", &temp, &tval) != EOF)
			{
				
				tlist = *list;
				
				*list = (List *) malloc(sizeof(List));
				
				(*list)->label = (char *) malloc(strlen(temp) + 1);
				strcpy((*list)->label, temp);
				(*list)->value = (tval+*pc);
				(*list)->next = tlist;
			}
			break;
		}
		
		fscanf(in, "%s", &temp);
		
		if (temp[0] == 'U')
		{
			fscanf(in, "%s", &temp2);
			labelExists = 1;
		}
		
		tpc = currentPc + 1;
		
		if (labelExists)
		{
			fprintf(temp1, "   %d %s %s\n", *pc + currentPc, temp, temp2);
		} else {
			fprintf(temp1, "   %d %s\n", *pc + currentPc, temp);
			
		}
		
	}
	
	*pc += tpc;
	
	return 0;
}

int printFile(FILE *input)
{
	int c;
	rewind(input);
	do
	{
		c = fgetc(input);
		if (c != EOF)
			printf("%c", c);
	} while(c != EOF);
	
	return 0;
	
}

/* Finds a value in the list */
int find_val(char* label, List *list)
{
		
	while (list != NULL)
	{
		if (!strcmp(list->label, label))
			return list->value;
	
		list = list->next;
	}
	
	return -1;	
}

FILE *refine (FILE *temp1, List *list)
{
	char temp[50], temp2[50], temp3[17], *temp4, temp5[17];
	int line;
	int i;
	
	FILE *temp12 = fopen("temp2.tlf", "w+");
	unlink("temp2.tlf");
	
	rewind(temp1);
	
	while(1)
	{
		if (fscanf(temp1, "%d %s", &line, &temp) == EOF)
			break;
		
		if (temp[0] == 'U')
		{
			fscanf(temp1, "%s", &temp2);
			
			for (i=0; i < 8; ++i)
				temp3[i] = temp[i+1];

            for (i = 0; i <= 16; i++)
                temp5[i] = temp[i + 1];

			temp4 = decbin((bindec(temp5)+find_val(temp2, list)));
            
			strcpy(temp3, temp4);
				
		} else {
			for (i = 0; i < 17; i++)
				temp3[i] = temp[i];
		}
		
		fprintf(temp12, "%s\n", temp3);
			
	}	
	
	fclose(temp1);
	
	return temp12;
	
}

char* decbin(int n)
{
	int i;
	char *temp = (char *) malloc(sizeof(char)*17);
	
	if (n > 131071) //invalid number. return null array
	{
		temp[0] = '\0';
		return temp;
	}
		
	for (i = 15; i >= 0; i--)
	{
		if ((n % 2))
			temp[i] = '1';
		else
			temp[i] = '0';
		n /= 2;
	}
	
	temp[16] = '\0';
	
	return temp;
	
}

int bindec(char* input)
{
	int i = 0;
	int temp = 0;
	int j = 15;
	for (i = 0; i <= 15; i++) {
		if(input[i] == '1')
			temp += (int)pow((double) 2, (double)j);
        j--;
	}

	return temp;
}	

