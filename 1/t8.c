#include <stdio.h>


int main( void)

{
	int i=0;
	int j=1;
	int x;	
	int y;
	int z;	
	
	scanf("%d", &x);
	scanf("%d", &z);
	scanf("%d", &y);
	for (i=0;i<=x-1;i++)
	{
		printf("#");
		
	}
	printf("\n");
	i=0;
		
	for  (j=1;j<(z-1);j++)
	{
		 
		for (i=0;i<=(x-1);i++)
		
		{
	
			printf("#");
				
			for (i=1;i<=(x-2);i++)
			{
				printf(".");
			}
			if (i == (x-1))
			{
				printf("#");	
			}		
		}		
		printf("\n");
		i=0;		
	}		
	if (j == (z-1))
	{
		for (i=0;i<=(x-1);i++)
		{
			printf("#");
		}
		printf("\n");
	}	
  	return 0;
}
