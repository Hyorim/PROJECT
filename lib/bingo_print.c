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

int main()
{
	int i,j;
	int z=1;
	int arr[5][5];
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			arr[i][j]=z;
			z++;
		}
	}
	arr[1][3]=-1;
	arr[2][2]=-1;
	arr[0][1]=-1;
	arr[4][2]=-1;
	bingo_print(arr);
}
