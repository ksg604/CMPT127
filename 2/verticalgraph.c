#include <stdio.h>
#include <math.h>

int main( void )

{
    int i = 0;
    int j; 
    int input =0;
    int num=0;
    int val;  
    int table[80];
    while (scanf("%d", &val) != EOF)
    {
      table[i]=val;
      i++;
      input++;

    }   
	
    i=0;
    for (i=0;i < input;i++)
    {
	if (table[i] > num)
	{
		num = table[i];
	}
    }
	i=0;

	for (i=0;i < input;i++)
	{
		table[i]= num - table[i];		

	}

	i=0;

	for (i=0;i < num;i++)
	{ 		
 		for (j = 0;j < input;j++)
 		{
 			if (table[j]>0)
	 		{
	 			printf(" ");
	 		}
	 		else if (table[j]<=0)
	 		{
	 			printf("#");
	 		}	 		
 		}

 		printf("\n");
 		j=0;

 		for (j=0;j<input;j++)
		{
			table[j] = (table[j]-1);
		}
	}

	return 0;
}
