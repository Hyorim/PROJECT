#include <stdio.h>

int user_delete(int(*user_arr)[5],int delete_num)
{
        int i,j;
        int user_cur=0;
        for (i=0;i<5;i++)
        {
                for (j=0;j<5;j++)
                {
                        if(user_arr[i][j]==delete_num)
                        {
                                user_arr[i][j]=-1;
                                user_cur=((5*i)+j)+1;
                                return user_cur;
                        }
                }
        }
        return 0;
}


