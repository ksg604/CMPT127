#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intarr.h"

intarr_t* intarr_create( unsigned int len )
{

	intarr_t* temp = malloc(sizeof(intarr_t));

	if(temp == 0)
	{
		return NULL;
	}

	temp->len = len;
	temp->data = malloc(sizeof(int)*len);

	
	
	
	return temp;
}

void intarr_destroy( intarr_t* ia )
{
	if(ia == NULL)
	{
		return;
	}
	if(ia->data == NULL)
	{
		return;
	}
	free(ia);
}


intarr_result_t intarr_set( intarr_t* ia, 
			    unsigned int index, 
			    int val )
{
	if((index < ia->len) && (index >= 0))
	{
		ia->data[index] = val;
		return INTARR_OK;
	}
	else if(ia == NULL)
	{
		return INTARR_BADARRAY;
	}
	else
	{
		return INTARR_BADINDEX;
	}
	
	

	
}


intarr_result_t intarr_get( const intarr_t* ia, 
			    unsigned int index, 
			    int* i )
{
	if((index < ia->len) && (index >= 0) && (i != NULL))
	{
		*i = ia->data[index];
		return INTARR_OK;
	}
	else if (ia == NULL)
	{
		return INTARR_BADARRAY;
	}
	else
	{
		return INTARR_BADINDEX;
	}

		
}

intarr_t* intarr_copy( const intarr_t* ia )
{
	if(ia == NULL)
	{
		return NULL;
	}

	intarr_t * duplicate = malloc(sizeof(intarr_t));

	if(duplicate == NULL)
	{
		return NULL;
	}

	duplicate->len = ia->len;
	
	int numbytes = duplicate->len * sizeof(int);
	duplicate->data = malloc(numbytes);

	if(numbytes == 0)
	{
		return NULL;
	}

	memcpy(duplicate->data,ia->data,numbytes);

	
	
	return duplicate;
}

intarr_result_t intarr_sort( intarr_t* ia )
{
	if(ia == NULL)
	{
		return INTARR_BADARRAY;
	}

	//Quicksort sorting algorithm
	for(int i = 0; i < ia->len; i++)
	{
		int value = ia->data[i];
		int blank = i;

		while(blank > 0 && value < ia->data[blank-1])
		{
			ia->data[blank] = ia->data[blank-1];
			blank--;
		}
		ia->data[blank] = value;
	}
				
	return INTARR_OK;
}

intarr_result_t intarr_find( intarr_t* ia, int target, int* i )
{
	if(ia == NULL)
	{
		return INTARR_BADARRAY;
	}

	for(int j = 0; j < ia->len; j++)
	{
		if((target == ia->data[j]) && (i != NULL))
		{
			*i = j;
			return INTARR_OK;
		}
		
	}
	return INTARR_NOTFOUND;
}

intarr_result_t intarr_push( intarr_t* ia, int val )
{
	if(ia == NULL)
	{
		return INTARR_BADARRAY;
	}

	ia->len = ia->len + 1;
	int numbytes =  sizeof(int) * ia->len;
	if(numbytes == 0)
	{
		return INTARR_BADALLOC;
	}
	
	ia->data = realloc(ia->data,numbytes);

	ia->data[ia->len-1] = val;

	return INTARR_OK;	
	

}


intarr_result_t intarr_pop( intarr_t* ia, int* i )
{
	if(ia == NULL)
	{
		return INTARR_BADARRAY;
	}
	
	else if(ia->len == 0)
	{
		return INTARR_BADINDEX;
	}
	else
	{
		if(i != NULL)
		{
			*i = ia->data[ia->len-1];
		}
		ia->data[ia->len-1] = 0;
		ia->len = ia->len -1;
		return INTARR_OK;
	}

}

intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen )
{
	if(ia == NULL)
	{
		return INTARR_BADARRAY;
	}

	unsigned int original_len = ia->len;

	int numbytes = sizeof(int) * newlen;
	if(numbytes == 0)
	{
		return INTARR_BADALLOC;
	}
	
	ia->len = newlen;
	ia->data = realloc(ia->data,numbytes);

	
	if(newlen > original_len)
	{
		while(original_len < newlen)
		{
			ia->data[original_len] = 0;
			original_len++;
		}
	}
	
	return INTARR_OK;
	

	
}

intarr_t* intarr_copy_subarray( intarr_t* ia, 
				unsigned int first, 
				unsigned int last )
{
	if(ia == NULL)
	{
		return NULL;
	}
	else if(last < first)
	{
		return NULL;
	}

	//All conditions for first and last being out of bounds.
	else if((first < 0) || (first >= ia->len) || (last < 0) || (last >= ia->len))
	{
		return NULL;
	}

	intarr_t * copysubarray = malloc(sizeof(intarr_t));

	if(copysubarray == 0)
	{
		return NULL;
	}

	copysubarray->len = last-first+1;
	int numbytes = sizeof(int) * copysubarray->len;
	if(numbytes == 0)
	{
		return NULL;
	}

	copysubarray->data = malloc(sizeof(int)*numbytes);
	
	int j = 0;
	for(int i = first; i <= last; i++)
	{
		copysubarray->data[j] = ia->data[i];
		j++;
	}

	

	return copysubarray;
}

