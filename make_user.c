#include <stdio.h>

int user_temp[5][5]={{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-$

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
        int i,j;
        int num=0;
        for (i=0;i<5;i++)
        {
                for (j=0;j<5;j++)
                {
                        printf("Please enter numbers.");
                        scanf("%d",&num);
                        if(overlap(num)==0)
                        {
                                printf("Please enter another numbe$
                                scanf("%d",&num);
                        }
                        user_arr[i][j]=num;
                        user_temp[i][j]=num;
                }
        }
}

void main (void)
{
        int user_arr[5][5]={0,};
        user_make(user_arr);
        int i,j;
        for(i=0;i<5;i++)
        {
                for(j=0;j<5;j++)
                {
                        printf("%d ",user_arr[i][j]);
                }
        	printf("\n");
        }
}

