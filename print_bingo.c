#include <stdio.h>

int print_bingo(int(*arr)[5])
{
        int i,j;
        for (i=0;i<5;i++)
        {
                for (j=0;j<5;j++)
                {
                        printf(" %d ",arr[i][j]);
                }
                printf("\n");
        }
}
