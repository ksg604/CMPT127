#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intarr.h"

int intarr_save_binary( intarr_t* ia, const char* filename )
{
	
	//-1 is a non-zero error code returned on failure when the array is null or if the file is null.
	if (filename == NULL)
	{
		return -1;
	}

	if (ia == NULL)
	{
		return -1;
	}
	

	FILE * filenamep = fopen(filename,"w");

	if(fwrite(ia->data,sizeof(int),ia->len,filenamep) == ia->len)
	{
		fclose(filenamep);
		return 0;
	}
	else
	{
		fclose(filenamep);
		return -1;
	}
}

intarr_t* intarr_load_binary( const char* filename )
{
	
	if(filename == NULL)	
	{
		return NULL;
	}

	FILE * filenamep = fopen(filename,"r");
	if(filenamep == NULL)
	{
		return NULL;
	}
 	fseek(filenamep,0,SEEK_END);
	intarr_t * ia = malloc(sizeof(intarr_t));
	
	ia->len = ftell(filenamep)/sizeof(int);
	ia->data = malloc(sizeof(int)*ia->len);

	fseek(filenamep,0,SEEK_SET);
	

	

	if(fread(ia->data,sizeof(int),ia->len,filenamep) == ia->len)
	{
		fclose(filenamep);
		return ia;
	}
	else
	{
		fclose(filenamep);
		return NULL;
	}
}
	

	















