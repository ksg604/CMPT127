#include <stdio.h>
#include <math.h>

int main(void) 
{
	float f = 0;
	
	if(scanf( "%f", &f ) == 1) 
	{
		printf("%.0f %.0f %.0f\n", floorf(f), roundf(f), ceilf(f) );	
	}
	else
	{
		printf("scanf error: (%.0f)\n", f);
	}
	

	return 0;
}
