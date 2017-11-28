#include <stdio.h>

#include <stdio.h>

int bingo_row(int (*arr)[5],int num)
{
        int i=0;
        while(i!=5)
        {
                if(arr[num/5][i]!=-1)
                {
                        return 0;
                }
                i++;
        }
        return 1;
}


