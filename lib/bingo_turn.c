#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// user win return 0
// com win retrun 1

int bingo_turn()
{
	int user_rsp;
	int com_rsp;
	srand((int)time(NULL));

	printf("Let's order. Pick one. Rock=1, Scissors=2, Paper=3\n");
	scanf("%d",&user_rsp);
	com_rsp=rand()%3+1;
	if(user_rsp<com_rsp||user_rsp==com_rsp)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
