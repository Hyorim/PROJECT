#include <stdio.h>

int bingo_diag_left(int(*user_arr)[5])
{
        int x;
        int bingo_diag_left=0;
        for(x=0;x<5;x++)
        {
                if(user_arr[x][x]==-1)
                {
                        bingo_diag_left++;
                }
        }
        if(bingo_diag_left==5)
        {
                return 1;
        }
        else
        {
                return 0;
        }
}
