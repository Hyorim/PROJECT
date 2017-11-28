#include <stdio.h>
#include <time.h>

int bingo_test(int(*arr)[5])
{
	int row = bingo_row(arr);
	int col = bingo_column(arr);
	return (row+col);
}


int main (void)
{
	int user_arr[5][5],com_arr[5][5];
	srand((int)time(NULL));

	printf("Make Bingoboard\n");

	user_make(user_arr);
	com_make(com_arr);

	printf("Start Bingo\n Pick a number\n");
	int pick_num;
	int user_loc,com_loc;
	int user_bingo = 0;
	int com_bingo = 0;
	int turn = 0;

	//while((user_bingo != 5)&&(com_bingo != 5))
	//{

	switch(turn%2){
	case 0: scanf("%d",&pick_num);
		printf("Number is %d\n",pick_num);
	case 1: pick_num=(rand()%25)+1;
		printf("Number is %d\n",pick_num);
	//function=not duplication(user_num!=com_num);
	}
	turn++;

	user_loc = user_delete(user_arr,pick_num);
	com_loc = com_delete(com_arr,pick_num);

	if(user_loc != 0)
	{
		user_bingo = user_bingo+bingo_test(user_arr,user_loc);
		//if(user_loc == )
	}
	if(com_loc != 0)
	{
		com_bingo = com_bingo+bingo_test(com_arr,com_loc);
		//if(com_loc == )
	}


	//function print bingoboard


	//}
	//

	if (user_bingo == 5)
	{
		printf("You win. Congratulation!\n");
	}
	else if (com_bingo == 5)
	{
		printf("You lost. Try again later!\n")
	}
}
