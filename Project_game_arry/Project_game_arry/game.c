#define _CRT_SECURE_NO_WARNINGS

#include "game.h"


void menu() {
	printf("*************   GAME   **************\n");
	printf("********* 1. paly     0. exit  *********\n");
	printf("************************************\n");
}

void game() {
	
	char ret = 0;		//the return value of IsWin
	char board[ROW][COL] = {0};		//store the content of board.
	
	InitBoard(board, ROW, COL);		//initialize the board
	
	DisplayBoard(board, ROW, COL);
	
	while (1) {
		PlayerMove(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		DisplayBoard(board, ROW, COL);

		ComputerMove(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		DisplayBoard(board, ROW, COL);
	}

	if (ret == '*') {
		printf("Player win\n");
	}
	else if (ret == '#') {
		printf("You fail....\n");
	}
	else {
		printf("DogFall....\n");
	}
	DisplayBoard(board, ROW, COL);
}
// CP win --> '#'
//Player win --> '*'
//Dogfall --> 'Q'
//keep go --> 'C'


int main() {
	srand((unsigned int) time(NULL));
	int input = 0;
	do {
		menu();    //print the selecting menu
		printf("Please choose:  ");
		scanf("%d", &input);
		switch (input) {
			case 1:
				//printf("Starting Game.....\n");
				game();
				break;
			case 0:
				printf("Exiting.........\n");
				break;
			default:
				printf("Choosing Wrong........\n\n");
				break;
		}
	} while (input);
	return 0;
}