#include <stdio.h>
int main( )
{
 
    unsigned long int charcount=0;
    unsigned long int wordcount=0;
    unsigned long int linecount=0;
    char c;
    int incWord=1; //Used to track whether or not previous character was '\n' or a letter
		   //If value is 1, increment wordcount if 0, don't increment

    while((c=getchar())!= EOF )  
    {    
    	charcount++;
    	if (c=='\n')
    	{
    		linecount++;
        	incWord=1;
    	}
    	
    	else if ((c>='a' && c<='z') || (c>='A' && c<='Z') || (c=='\''))
    	{
    
    		if (incWord==1)
    		{
    			wordcount++;
    			incWord=0;
    		}
    		
    	}
		else
		{
			incWord=1;
		}
    	
    }	
    printf( "%lu %lu %lu\n", charcount, wordcount, linecount ); 
    return 0; 		
} 
