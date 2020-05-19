#include <stdio.h>
#include <stdlib.h>
#include "point_array.h"


void point_array_init( point_array_t* pa)
{

	pa->len = 0;
	pa->reserved = 0;
	pa->points = realloc(pa->points,sizeof(point_t));
}

void point_array_reset( point_array_t* pa )
{

	for(int i = 0; i < pa->len; i++)
	{

		pa->points[i].x = 0;
		pa->points[i].y = 0;
		pa->points[i].z = 0;
	}

	pa->len = 0;
	pa->points = realloc(pa->points, 0);
}

int point_array_append( point_array_t* pa, point_t* p)
{
	
	if(p == NULL)
	{
		return 0;
	}
	pa->len++;
	
	pa->points = realloc(pa->points, sizeof(point_t) * pa->len);
	if(pa->points == NULL)
	{
		return 1;
	}

	pa->points[pa->len-1].x = p.x;
	
	pa->points[pa->len-1].y = p.y;
	
	pa->points[pa->len-1].z = p.z;

	return 0;
}

int point_array_remove( point_array_t* pa, unsigned int i )
{
	
	//Index out of bounds
	if(i >= pa->len)
	{
		return 1;
	}

	pa->points[i].x = pa->points[pa->len-1].x;
	
	pa->points[i].y = pa->points[pa->len-1].y;

	pa->points[i].z = pa->points[pa->len-1].z;
	pa->len--;

	pa->points = realloc(pa->points,sizeof(point_t) * pa->len);
	return 0;
}
