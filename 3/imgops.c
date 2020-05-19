/*
 * imageops.c - Simple operations on images
 *
 * C laboratory exercises.
 * Richard Vaughan, 2014.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* PAIR SECTION BEGINS - WORK WITH YOUR PARTNER ON THESE TASKS */

/*-------------------------------------------------
  PART 0: DEMONSTRATION
*/


// get the value in the array at coordinate (x,y)
uint8_t get_pixel( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}

// set the pixel at coordinate {x,y} to the specified color
void set_pixel( uint8_t array[], 
        unsigned int cols, 
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
} 

// Set every pixel to 0 (black) 
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
	memset( array, 0, cols * rows * sizeof(array[0]) );
  // your code here.
}

// Returns a pointer to a freshly allocated array that contains the
// same values as the original array, or a null pointer if the
// allocation fails. The caller is responsible for freeing the array
// later.
uint8_t* copy( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows )
{
	uint8_t * temp = malloc(cols * rows * sizeof(uint8_t));

	if(temp == 0)
	{
		return NULL;
	}	

	for ( int i = 0; i < cols * rows; i++)
	{
		temp[i] = array[i];
	}
  	// your code here

	
  return temp;
}



/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE 
*/

/* TASK 1 - three easy functions to get started */

// Return the darkest color that appears in the array; i.e. the
// smallest value
uint8_t min( const uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows )
{
	uint8_t minVal = 255;
	for ( int i = 0; i < cols * rows; i++)
	{
		if(array[i] < minVal)
		{
			minVal = array[i];
		}
	}
  // your code here
  return minVal;
}

// Return the lightest color that appears in the array; i.e. the
// largest value
uint8_t max( const uint8_t array[], 
		 unsigned int cols, 
		 unsigned int rows )
{
	uint8_t maxVal = 0;
	for ( int i = 0; i < cols * rows; i++)
	{
		if(array[i] > maxVal)
		{
			maxVal = array[i];
		}
	}
  // your code here
  return maxVal;
}

// TASK 2

//  Replace every instance of pre_color with post_color.
void replace_color(  uint8_t array[], 
		     unsigned int cols, 
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color )
{

	for ( int i = 0; i < cols * rows; i++)
	{
		if ( array[i] == pre_color )
		{
			array[i] = post_color;
		}	
	}
  // your code here
}

/* TASK 3  - two functions */


// flip the image, left-to-right, like in a mirror.
void flip_horizontal( uint8_t array[], 
              unsigned int cols, 
              unsigned int rows )
{
	int temp;
	int start = 0;
	int end = cols - 1;
	
	for(int i = 0; i < rows; i++)
	{
		
		while(start < end)
		{	
			//For each new row, find the starting and ending index.
			int startIndex = cols * i + start;
			int endIndex = cols * i + end;
			
			//Swap
			temp = array[startIndex];	
			array[startIndex] = array[endIndex];
			array[endIndex] = temp;
			start++;
			end--;
		}
		//Reinitialize left and right for every row
		start = 0;
		end = cols-1;
	}
		
}

// flip the image top-to-bottom.
void flip_vertical( uint8_t array[], 
            unsigned int cols, 
            unsigned int rows )
{
	int temp;
	int top = 0;
	int bottom = rows-1;
	
	while(top < bottom)
	{
		for(int i = 0; i < cols; i++)
		{

			//For each new column find the start and end indices
			int startIndex = (cols * top) + i;
			int endIndex = (cols * bottom) + i;
			
			//Swap 
			temp = array[startIndex];
			array[startIndex] = array[endIndex];	
			array[endIndex] = temp;	
		}
		//Reinitialize top and bottom after every row
		top++;
		bottom--;
	}
	
}

/* TASK 4 */

// Find the first coordinate of the first pixel with a value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color(  const uint8_t array[], 
		   unsigned int cols, 
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{


	int start = 0;
	int end = cols;
	
	for(int i = 0; i < rows; i++)
	{
		while(start < end)
		{
			int index = cols * i + start;
			if (array[index] == color)
			{
				*x = start;
				*y = i;
				return 1;
			}
			start++;
		}
		start = 0;
	}

	int top = 0;
	int bottom = rows;
	while(top < bottom)
	{
		for(int i = 0; i < cols; i++)
		{
			int index = (cols * top) + i;
			if(array[index] == color)
			{
				*x = i;
				*y = top;
				return 1;
			}
		}
		top++;
	}
			
			
		
    return 0;
}


/* TASK 5 */

// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade. 
void invert( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows )
{
    // your code here

	int start = 0;
	int end = cols;
	
	for(int i = 0; i < rows; i++)
	{
		while(start < end)
		{
			int index = cols * i + start;
			array[index] = 255-array[index];
			start++;
		}
		start = 0;
	}
			
	
}

/* TASK 6 */

// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Any resulting value over 255 is
// thresholded to 255.
void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
	int start = 0;
	int end = cols;
	
	for(int i = 0; i < rows; i++)
	{
		while(start < end)
		{
			int index = cols * i + start;
			double val = round(scale_factor * (double)(array[index]));
			if(val > 255.0)
			{
				array[index] = 255;
			}
			else
			{
				array[index] = (uint8_t)val;
			}
			start++;
		}
		start = 0;
	}
}


/* TASK 7 */

// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max(). 
void normalize( uint8_t array[],
        unsigned int cols,
        unsigned int rows )
{
	int start = 0;
	int end = cols;
	int oldMin = min(array,cols,rows);
	int oldMax = max(array,cols,rows);
	int oldRange = oldMax - oldMin;
	int newMax = 255;
	int newMin = 0;
	int newRange = newMax - newMin;
	
	for(int i = 0; i < rows; i++)
	{
		while(start < end)
		{
			int index = cols * i + start;	
			double scale = ((double)array[index] - (double)oldMin) / oldRange;
			double newVal = round((newRange*scale) + newMin);
			array[index] = (uint8_t)newVal;
			start++;
		}
		start = 0;
	}
				
	
			
    // your code here
}

/* TASK 8 */

// Return a new image of size rows/2 by cols/2 If the original image              
// has an odd number of columns, ignore its rightmost column. If the              
// original image has an odd number of rows, ignore its bottom row.               
// The value of a pixel at (p,q) in the new image is the average of               
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in               
// the original image.                                                            
uint8_t* half( const uint8_t array[],
	       unsigned int cols,
	       unsigned int rows )
{
	
	unsigned int newCols;
	unsigned int newRows;

	if(rows % 2 == 1)
	{
		newRows = rows-1;
	}
	else
	{
		newRows = rows;
	}
	if(cols % 2 == 1)
	{
		newCols = cols-1;
	}
	else
	{
		newCols = cols;
	}

	uint8_t * temp = malloc(newCols/2 * newRows/2 * sizeof(uint8_t));


	int x = 0;
	int image_width = newCols/2;

	
	for(int y = 0; y < newRows/2; y++)
	{
		while(x < image_width)
		{
			int index = image_width * y + x;
			const uint8_t pixel1 = array[cols * (2*y) + (2*x)];
			const uint8_t pixel2 = array[cols * (2*y) + (2*x+1)];
			const uint8_t pixel3 = array[cols * (2*y+1) + (2*x+1)];
			const uint8_t pixel4 = array[cols * (2*y+1) + (2*x)];
			double avg = round(((double)pixel1 + (double)pixel2 + (double)pixel3 + (double)pixel4)/4.00);

			temp[index] = (uint8_t)avg;
			x++;
		}
		x = 0;
	}
		
  // your code here
  return temp;
}




/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS

  These functions operate only on a rectangular region of the array
  defined by a (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).

  The region includes all the columns from [left, right-1] inclusive,
  and allthe rows from [top, bottom-1] inclusive.
  
  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.

  The area of the region is right-left * bottom-top pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.
 
  In every function, use assert() to test bounds on the region
  corners.
*/

/* TASK 9 */

// Set every pixel in the region to color. If the region is empty, the
// image must be unchanged.
void region_set( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows,
         unsigned int left,
         unsigned int top,
         unsigned int right,
         unsigned int bottom,
         uint8_t color )
{
	assert(left >= 0 && left <= cols);
	assert(right >= 0 && right <= cols);
	assert(bottom >= 0 && bottom <= rows);
	assert(top >= 0 && top <= rows);


	if(left == right || top == bottom)
	{
		return;
	}
	
	
	int start = left;
	int end = right;
	for(int i = top; i < bottom; i++)
	{
		while(start < end)
		{
			int index = cols * i + start;
			array[index] = color;
			start++;
		}
		start = left;
	}
			

		
    // your code here
}

/* TASK 10 */

// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate( const uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    unsigned int left,
                    unsigned int top,
                    unsigned int right,
                    unsigned int bottom )
{
	assert(left >= 0 && left <= cols);
	assert(right >= 0 && right <= cols);
	assert(bottom >= 0 && bottom <= rows);
	assert(top >= 0 && top <= rows);

	if(left == right || top == bottom)
	{
		return 0;
	}
	
	int start = left;
	int end = right;
	unsigned long int sum = 0;
	
	for(int i = top; i < bottom; i++)
	{
		while(start < end)
		{
			int index = cols * i + start;
			sum = sum + array[index];
			start++;
		}
		start = left;
	}

    // your code here
    return sum;
}

/* TASK 11 */

// Get a new image which is a copy of the region. Empty regions return
// a null pointer. If memory allocation fails, return a null
// pointer. The caller is responsible for freeing the returned array
// later.
uint8_t* region_copy( const uint8_t array[], 
              unsigned int cols, 
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{

	assert(left >= 0 && left <= cols);
	assert(right >= 0 && right <= cols);
	assert(bottom >= 0 && bottom <= rows);
	assert(top >= 0 && top <= rows);

	if(left == right || top == bottom)
	{
		return NULL;
	}

	uint8_t * temp = malloc((bottom-top) * (right-left) * sizeof(uint8_t));
	
	if(temp == 0)
	{
		return NULL;
	}
	
	int start = left;
	int end = right;
	int k = 0;


	for(int i = top; i < bottom; i++)
	{
		while(start < end)
		{
			int index = cols * i + start;
			temp[k] = array[index];
			k++;
			start++;
		}
		start = left;
	}

		
	


    // your code here
    return temp;
}


