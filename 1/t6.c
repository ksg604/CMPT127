#include <stdio.h>
#include <math.h>

int main(void) 
{
	float f = 0;
	float largest;
	float smallest;
	float mean; //arithmetic mean
	int count = 0; //number of input values
	float sum = 0; //for calculating mean average
	
	int result; //Integer that tests whether scanf read input successfully or not. 

	largest = -100000;
	smallest = 100000;

	while (result != EOF) 
	{	
		result = scanf( "%f", &f );

		if((f <= -100000) || (f >= 100000))
		{	
			printf("Input value is not in the range [-100000,100000], discarding input value..\n");
			continue;
		}
			
		if(result == EOF)
		{	
			printf("%.2f %.2f %.2f\n",smallest,largest,mean);
			break;
		}	

		if(f>largest)
		{
			largest = f;
		}
		if(f<smallest) 
		{
			smallest = f;
		}
		count++;
		
		sum = sum + f;
		mean = sum / count;

	}
		

	return 0;
}
