#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intarr.h"
int intarr_save_json( intarr_t* ia, const char* filename )
{

	if(filename == NULL)
	{
		return -1;
	}
	if(ia == NULL)
	{
		return -1;
	}
	FILE * filenamep = fopen(filename,"w+");
	fprintf(filenamep,"[");
	for(int i = 0; i < ia->len; i++)
	{
		fprintf(filenamep," %d",ia->data[i]);
		if (i == ia->len-1)
        	{
            		break;
		}
		else
		{
			fprintf(filenamep,",");
		}
	}
	fprintf(filenamep," ]");
	fclose(filenamep);
	return 0;
}

intarr_t* intarr_load_json( const char* filename )
{

	if(filename == NULL)
	{
		return NULL;
	}
	
	FILE * filenamep = fopen(filename,"r+");
	if(filenamep == NULL)
	{
		return NULL;
	}



	//n is number of ,
	int n = 0;
	int c;

	intarr_t * ia =malloc(sizeof(intarr_t));
	
	fseek(filenamep, 0, SEEK_SET);	
	while(c != EOF)
	{	
		putchar(c);
		c = getc(filenamep);
		if(c == ',')
		{
			n = n + 1;
		}
	}


	
	//Consider the case if array is empty, then return empty array
	if (n == 0)
   	{
       		ia->len = 0;
        	ia->data = NULL;
		return ia;

   	}
	//Length of array is number of ',' + 1

	ia->len = n+1;

        ia->data = malloc(sizeof(int)*ia->len);

	fseek(filenamep, 0, SEEK_SET);	

	
	int temp;
	for ( int i = 0; i <= n; i++)
	{

		while (fscanf(filenamep, "%d", &temp) != 1)
        	{
           		fseek(filenamep, 1, SEEK_CUR);
            
		}
		ia->data[i] = temp;
	}

	fseek(filenamep,0,SEEK_END);
	fclose(filenamep);
	return ia;
}
		

	
	

