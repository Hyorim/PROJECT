#include <stdio.h>

int com_delete(int(*array)[5],int num)
{

	int i=0;
	while(i!=24)
	{
		if(array[i/5][i%5]==num)
		{
			array[i/5][i%5]=-1;
			return (i+1);
		}
		i++;
	}
	return 0;

}

