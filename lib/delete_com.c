#include <stdio.h>

int com_delete(int(*array)[5],int num)
{

	int i=0;
	while(i!=24)
	{
		if(array[i/5][i%5]==num)
		{
			array[i/5][i%5]=-1;
			return (i+1);
		}
		i++;
	}
	return 0;

}

int main(void)
{
	int arr[5][5];
	int i,j;
	int num=25;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			arr[i][j]=num;
			num--;
		}
	}

	int u=com_delete(arr,9);
	printf("\n %d \n",u);
	for(i=0;i<5;i++)
        {
        	for(j=0;j<5;j++)
                {
                        printf(" %d ",arr[i][j]);
                }
	printf("\n");
        }


}

