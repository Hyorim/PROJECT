#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int temp[50]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

void com_make(int(*array)[5])
{

	int i=0;
	int k=0;
	srand((int)time(NULL));
	while(k<25)
	{
		int num=(rand()%25)+1;
		if(temp[num-1]==-1)
		{
			array[i/5][i%5]=num;
			temp[num-1]=0;
			i++;
			k++;
		}
	}
}

