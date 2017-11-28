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
        if(bingo_diag_right==5)
        {
                return 1;
        }
        else
        {
                return 0;
        }
}
