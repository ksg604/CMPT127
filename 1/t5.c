#include <stdio.h>
#include <math.h>


int main(void) 
{
	float f = 0;
	int result;


	while (1) 
	{		

		result = scanf( "%f", &f );	
		

		if(result == 1)
		{
			printf("%.0f %.0f %.0f\n", floorf(f), roundf(f), ceilf(f) );	
		}
		else if(result == EOF)
		{	
			printf("Done.\n");
			break;
		}
		else // Invalid input case.
		{	
			while((getchar()) != '\n'); //flush input buffer of any invalid input
		}
	}	

	return 0;
}
