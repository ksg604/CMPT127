#include <stdio.h>
#include <math.h>

int main(void) 
{
	float f = 0;
	
	scanf( "%f", &f );
	
	printf("%.0f %.0f %.0f\n", floorf(f), roundf(f), ceilf(f) );

	return 0;
}
