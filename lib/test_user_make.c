#include <stdio.h>

int user_temp[5][5]={{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1}};

int overlap(int num)
{
        int i,j;
        for(i=0;i<5;i++)
        {
                for(j=0;j<5;j++)
                {
                        if(user_temp[i][j]==num)
                        {
                                return 0;
                        }
                }
        }
        return 1;
}

void user_make(int(*user_arr)[5])
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
                        while(overlap(num)==0||num>50||num<1)
                        {
                                printf("Other number : ");
                                scanf("%d",&num);
                        }
                        user_arr[i][j]=num;
                        user_temp[i][j]=num;
                }
        }
}

int main()
{
	int arr[5][5];
	int i,j;
	user_make(arr);
        for (i=0;i<5;i++)
        {
                for (j=0;j<5;j++)
                {
			printf("%2d",arr[i][j]);
		}
		printf("\n");
	}
}
