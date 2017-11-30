#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include "bingo_column.h"
#include "bingo_row.h"
#include "bingo_diag_right.h"
#include "bingo_diag_left.h"
#include "bingo_print.h"
#include "com_make.h"
#include "com_delete.h"
#include "user_delete.h"
#include "user_make.h"

int bingo_test(int(*arr)[5],int loc)
{
	int row = bingo_row(arr,loc-1);
	int col = bingo_column(arr,loc-1);
	return (row+col);
}

void term(int sig)
{
	printf("Give up game.\n");
	exit(0);
}

int main (void)
{
	int user_arr[5][5],com_arr[5][5];
	srand((int)time(NULL));

	struct sigaction sa;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;
	sa.sa_handler=term;
	if(sigaction(SIGINT,&sa,NULL)==-1)
	{
		perror("sigaction");
		exit(0);
	}


	printf("Game start.(ctrl+c = Give up)\nMake Bingoboard\n");

	//user_make(user_arr);
	int a,b;
	int c=1;
	for(a=1;a<6;a++)
	{
		for(b=1;b<6;b++)
		{
			user_arr[a-1][b-1]=c;
			c++;
		}
	}
	com_make(com_arr);

	//printf("Start Bingo\n Pick a number\n");
	int pick_num;
	int user_loc,com_loc;
	int user_bingo = 0;
	int com_bingo = 0;
	int turn = 0;

	int user_num[50];
	int com_num[50];
	int i,j;

	int dup[50];
	for(i=0;i<50;i++)
	{
		dup[i]=-1;
		user_num[i]=-1;
		com_num[i]=-1;
	}

	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			user_num[user_arr[i][j]-1]=1;
			com_num[com_arr[i][j]-1]=1;
		}
	}
	int diag[10]={1,7,13,19,25,5,9,13,17,21};
	int try_num=0;


	while((user_bingo < 5)&&(com_bingo < 5))
	{
		if((turn%2)==0)
		{
			printf("Pick a number\n");
			scanf("%d",&pick_num);
			while((pick_num < 1)||(pick_num > 50))
			{
				printf("Please 0<number<51\n");
				scanf("%d",&pick_num);
			}

                        printf("[USER]Number is %d\n",pick_num);
			if(user_num[pick_num-1]==-1)
			{
				try_num=1;
			}
			else
			{
				user_num[pick_num-1]=-1;
				try_num=0;
			}
		}
		else if((turn%2)==1)
		{
                	pick_num=(rand()%50)+1;
                        printf("[COM]Number is %d\n",pick_num);
			if(com_num[pick_num-1]==-1)
			{
				try_num=1;
			}
			else
			{
				com_num[pick_num-1]=-1;
				try_num=0;
			}
		}

		int temp=0;
		if (dup[pick_num-1]==-1)
		{
			dup[pick_num-1]=1;
			temp=1;
		}
		if(((dup[pick_num-1]== 1)&&(temp != 1))||(try_num==1))
		{
			while(( dup[pick_num-1] == 1 )||(try_num == 1))
			{
				if(try_num == 1)
				{
					printf("Not exist. Try again\n");
				}
				else if(dup[pick_num-1]==1)
				{
					printf("Duplication! Try again\n");
				}


				if((turn%2)==0)
				{
					scanf("%d",&pick_num);
					while((pick_num < 1)||(pick_num > 50))
					{
						printf("Please 0<number<51\n");
						scanf("%d",&pick_num);
					}
					printf("[USER]Number is %d\n",pick_num);
					if(user_num[pick_num-1]==-1)
					{
						try_num=1;
					}
					else
					{
						user_num[pick_num-1]=-1;
						try_num=0;
					}


				}
				else if((turn%2)==1)
				{
					pick_num=(rand()%50)+1;
					printf("[COM]Number is %d\n",pick_num);
					if(com_num[pick_num-1]==-1)
					{
						try_num=1;
					}
					else
					{
						com_num[pick_num-1]=-1;
						try_num=0;
					}
				}
			}
                }

		turn++;

		user_loc = user_delete(user_arr,pick_num);
		com_loc = com_delete(com_arr,pick_num);

		if(user_loc != 0)
		{
			user_bingo = user_bingo+bingo_test(user_arr,user_loc);
			int i;
			for(i=0;i<10;i++)
			{
				if((user_loc==diag[i])&&(i<5))
				{
					user_bingo=user_bingo+bingo_diag_left(user_arr);
				}
				else if((user_loc==diag[i])&&(i>4))
				{
					user_bingo=user_bingo+bingo_diag_right(user_arr);
				}
			}
		}
		if(com_loc != 0)
		{
			com_bingo = com_bingo+bingo_test(com_arr,com_loc);
			int i;
			for(i=0;i<10;i++)
			{
				if((com_loc==diag[i])&&(i<5))
				{
					com_bingo=com_bingo+bingo_diag_left(com_arr);
				}
				else if((com_loc==diag[i])&&(i>4))
				{
					com_bingo=com_bingo+bingo_diag_right(com_arr);
				}
			}
		}
		printf("\n");
		bingo_print(user_arr);

		printf("user bingo is %d\n",user_bingo);
	}


	if (user_bingo > 4)
	{
		bingo_print(user_arr);
		printf("\nYou win. Congratulation!\n");
	}
	else if (com_bingo > 4)
	{
		printf("\nCOM's bingo_board\n");
		bingo_print(com_arr);
		printf("\nYou lost. Try again later!\n");
	}
}
