#include <stdio.h>

int bingo_print(int(*arr)[5])
{
        int i,j;
        for (i=0;i<5;i++)
        {
                for (j=0;j<5;j++)
                {
                        if(arr[i][j]==-1)
                        {
                                printf(" O ");
                        }
                        else
                        {
                                printf("%2d ",arr[i][j]);
                        }
                }
                printf("\n");
	}
}
