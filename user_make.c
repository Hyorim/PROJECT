#include <stdio.h>

int temp[5][5]={{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1}};


int overlap(int num)
{
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(temp[i][j]==num)
			{
				return 0;
			}
		}
	}
	return 1;
}


void user_make(int(*arr)[5])
{
	int i;
	int j;
	int num=0;

	for (i=0;i<5;i++)
	{
		for (j=0;j<5;j++)
		{
			printf("Please enter numbers.");
			scanf("%d",&num);
			if(overlap(num)==0)
			{
				printf("Please enter another number.");
				scanf("%d",&num);
			}
			arr[i][j]=num;
			temp[i][j]=num;
		}
	}
}
