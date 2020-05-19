#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if(strstr(argv[1],argv[2]) == NULL)
	{
		printf("false\n");
	}
	else
	{
		printf("true\n");
	}
}
