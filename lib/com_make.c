#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int temp[25]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int check()
{
	int i;
	for(i=0;i<25;i++)
	{
		if(temp[i]==-1)
		{
			return 0;
		}
	}
	return 1;
}

void com_make(int(*array)[5])
{

	int i=0;
	srand((int)time(NULL));
	while(!check())
	{
		int num=(rand()%25)+1;
		if(temp[num-1]==-1)
		{
			array[i/5][i%5]=num;
			temp[num-1]=0;
			i++;
		}
	}
}

