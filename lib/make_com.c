#include <stdio.h>
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
	int j=0;
	srand((int)time(NULL));
	while(!check())
	{
		int num=(rand()%25)+1;
		if(temp[num-1]==-1)
		{
			array[i][j]=num;
			temp[num-1]=0;
			if(j==4)
			{
				j=0;
				i++;
			}
			else
			{
				j++;
			}
		}
	}
}

void main (void)
{
	int aa[5][5]={0,};
	com_make(aa);
	int i;
	int j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d ",aa[i][j]);
		}
	printf("\n");
	}
}

