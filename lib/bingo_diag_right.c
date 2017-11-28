#include <stdio.h>

int bingo_diag_right(int(*user_arr)[5])
{
        int x;
        int bingo_diag_right=0;
        for(x=0;x<5;x++)
        {
                if(user_arr[x][4-x]==-1)
                {
                        bingo_diag_right++;
                }
        }
        printf("bingo r_d is %d\n",bingo_diag_right);
        if(bingo_diag_right==5)
        {
                return 1;
        }
        else
        {
                return 0;
        }
}


int main()
{
        int a,i,j,delete_num;
        int user_arr[5][5]={0,};

        for (i=0;i<5;i++)
        {
                for (j=0;j<5;j++)
                {
                        user_arr[i][j]=-1;
                }
        }
	a=bingo_diag_right(user_arr);
	printf("%d",a);
}
