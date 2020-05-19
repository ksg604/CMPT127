int scrambled( unsigned int a[], unsigned int b[], unsigned int len )
{	
	int temp[100]; //Temporary storage to compare the two arrays

	if(len == 0)
	{
		return 1;
	}	
	for(int i = 0; i < 100; i++) //Initialize every value in temp array to 0
	{
		temp[i] = 0;	
	}
	for(int k = 0; k < len; k++) //Values in array a and b will be indices in temp array.
	{
		temp[a[k]]++;	//Increment index in temp pertaining to value in array a
		temp[b[k]]--;   //Decrement index in temp pertaining to value in array b
				//If temp does not end up with every index containing 0, there are values in a different from b.
	}
	for(int j = 0; j < 100; j++)
	{
		if(temp[j] != 0)
		{
			return 0;
		}
	}
	return 1;

	
}


