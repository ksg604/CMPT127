#include <stdio.h>
#include <math.h>

int main(void) 
{

	int numHash;
	int result; //Integer that tests whether scanf read input successfully or not. 

	while(1)
	{
		result = scanf( "%d", &numHash );	
		//test
		if(result == EOF)
		{		
			break;
		}

		for(int i = 0; i < numHash; i++) 
		{
		
			printf("#");
		}

		printf("\n");	

	}

	return 0;

}
