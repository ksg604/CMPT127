#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	//Count array keeps track of occurrences of each letter
	int count[26];
	char letter;
	char letters [26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	float freq;
	char c;
	float totalLetters;
	
	//Initially there are 0 letters
	for (int i = 0; i < 26; i++)
	{
		count[i] = 0;
	}
	
	//increment indices on count array pertaining to c
	while((c = getchar()) != EOF)
	{
		if (c >= 'a' && c <= 'z')
		{
			count[c-'a']++;
			totalLetters++;
		}
		else if (c >= 'A' && c <= 'Z')
		{
			count[c-'A']++;
			totalLetters++;
		}
	}
	

	
	for (int i = 0; i < 26; i++)
	{	

		freq = count[i]/totalLetters;
		letter = letters[i];
		if (count[i] != 0)
		{
			printf( "%c %.4f\n", letter, freq);
		}
	}
		

		
		
		
	
	
}
