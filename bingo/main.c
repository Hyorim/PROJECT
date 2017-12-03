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
#include "bingo_turn.h"

int turn=0;
int time_over=0;
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

void turn_change(int sig)
{
	printf("\nTime over! Turn change!\n");
	turn++;
	time_over=1;
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

        struct sigaction sb;
        sigemptyset(&sb.sa_mask);
        sb.sa_flags=0;
        sb.sa_handler=turn_change;
        if(sigaction(SIGALRM,&sb,NULL)==-1)
        {
                perror("sigaction");
                exit(0);
        }

	sigset_t block_set,prev_set;
	sigemptyset(&block_set);
	sigaddset(&block_set,SIGALRM);
	sigprocmask(SIG_BLOCK,&block_set,&prev_set);


	printf("Game start.(ctrl+c = Give up)\nMake Bingoboard\n");

	user_make(user_arr);
	com_make(com_arr);

	int pick_num;
	int user_loc,com_loc;
	int user_bingo = 0;
	int com_bingo = 0;

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


	turn=bingo_turn();
	if(turn==0)
	{
	printf("User first\n");
	}
	else
	{
	printf("Com first\n");
	}

	while((user_bingo < 5)&&(com_bingo < 5))
	{
		if((turn%2)==0)
		{
			pick_num=0;
			printf("Pick a number\n");
			sigprocmask(SIG_SETMASK,&prev_set,NULL);
			alarm(15);
			if(time_over != 1)
			{
				scanf("%d",&pick_num);
			}
			sigprocmask(SIG_BLOCK,&block_set,&prev_set);
			time_over=0;

		}
		if((turn%2)==0)
		{
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
			sleep(3);
                	pick_num=(rand()%50)+1;

			if(com_num[pick_num-1]==-1)
			{
				try_num=1;
			}
			else
			{
				com_num[pick_num-1]=-1;
				try_num=0;
				printf("[COM]Number is %d\n",pick_num);
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

				if((turn%2)==0)
				{
					if(try_num == 1)
					{
						printf("Not exist. Try again\n");
					}
					else if(dup[pick_num-1]==1)
					{
						printf("Duplication! Try again\n");
					}

					pick_num=0;
					sigprocmask(SIG_SETMASK,&prev_set,NULL);
					alarm(15);
					if(time_over != 1)
					{
						scanf("%d",&pick_num);
					}

					sigprocmask(SIG_BLOCK,&block_set,&prev_set);
					time_over=0;

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
					if(com_num[pick_num-1]==-1)
					{
						try_num=1;
					}
					else
					{
						com_num[pick_num-1]=-1;
						printf("[COM]Number is %d\n",pick_num);
						try_num=0;
					}
				}
			}
                }


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

		turn++;
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
