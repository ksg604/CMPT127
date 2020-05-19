#include <stdio.h>
#include <math.h>

int main( void )

{
	int i=0;
	int j=1;
	int w;	
	int b;
	int h;


	scanf("%d", &w);
	scanf("%d", &b);
	scanf("%d", &h);	
 	
	int count = floor( (w*h-w*j) / (2*h) );
 	
	for(i=0; i < count; i++)
	{
		printf(" ");
	}
	
	for (i=count; i < (w-count); i++)
	{

		printf("#");		
	}
	printf("\n");
	
	for  (j=2;j < h;j++)
	{
		count = floor( (w*h-w*j) / (2*h) );
		
		for(i=0;i < count;i++)
		{
			printf(" ");
		}
						
		printf("#");

		for (i=1;i <= (w-2*count-2); i++)
		{
			printf(".");
		}
				
		printf("#");	
										
		printf("\n");
				
	}
			
	if (h>1)
	{
		for (i=1; i <= w;i++)
		{
			printf("#");
			
		}
		printf("\n");
	}	
	
  	return 0;
}
