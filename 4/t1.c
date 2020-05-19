#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <math.h>


void draw_circle( uint8_t img[], 
                  unsigned int cols,
                  unsigned int rows,
		  int x,
		  int y,
		  int r,
		  uint8_t color )
{
	
	int start = 0;
	int end = cols;

	if(r == 0)
	{
		exit(0);
	}

	
	if (x > 0 && y > 0 && x < cols && y < rows)
	{
	

		for(int i = 0; i < rows; i++)
		{
			while(start < end)
			{
				int index = (cols * i) + start;
				if(round((float)sqrt(pow((double)(x-start),2.0) + pow((double)(y-i),2.0)))  < r)
				{
				
					img[index] = color;
				}
				start++;
			}
			start = 0;
	
		
		} 
	
	}
	
	else
	{
		exit(0);
	}





}
