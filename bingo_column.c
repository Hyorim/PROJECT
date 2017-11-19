#include <stdio.h>

int bingo_column(int(*user_arr)[5],int user_cur)
{
	int x,j;
	int bingo_col=0;
	j=user_cur%5;
	for(x=0;x<5;x++)
	{
		if(user_arr[x][j]==-1)
		{
			bingo_col++;
		}
	}
	printf("%d\n",bingo_col);
	if(bingo_col==5)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
