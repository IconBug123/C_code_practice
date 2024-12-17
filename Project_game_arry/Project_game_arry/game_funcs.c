#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++) {		//show the number of each colume
		printf("   %d", i + 1);
	}
	printf("\n");
	for (i = 0; i < row; i++) {
		//printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		int j = 0;
		for (j = 0; j < col; j++) {
			if (j == 0) {						//show the number of each row
				printf("%d|", i + 1);
			}
			printf(" %c ", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1) {		//do not print --- in the last row
			//printf("---|---|---\n");
			int j = 0;
			for (j = 0; j < col; j++) {		//print the ---
				if (j == 0) {
					printf(" |---");
				}
				else {
					printf("|---");
				}
				/*if (j < col - 1) {
					printf("|");
				}*/
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("Player inputs:>\n");
	while (1) {
		printf("Please input the x and y:> ");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {	//check the correction of input value
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("This position has already been occupied\n");
			}
		}
		else {
			printf("Please input correct position\n");
		}
	}
}


void ComputerMove(char board[ROW][COL], int row, int col) {
	printf("Computer playing:>\n");
	
	int x = 0;
	int y = 0;

	while (1) {
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}
}

//if board is full, then return 1, otherwise return 0;
int IsFull(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	
	//check row and colume
	for (i = 0; i < row; i++) {
		for (j = 0; j < col - 2; j++) {
			// check row
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j] != ' ') {
				return board[i][j];  
			}
			// check colum
			if (board[j][i] == board[j + 1][i] && board[j + 1][i] == board[j + 2][i] && board[j][i] != ' ') {
				return board[j][i];  
			}
		}
	}

	// check diagonal
	for (i = 0; i < row - 2; i++) {
		for (j = 0; j < col - 2; j++) {
			// chech main diagonal
			if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i][j] != ' ') {
				return board[i][j];  
			}
			// check reverse diagonal
			if (board[i][j + 2] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j] && board[i][j + 2] != ' ') {
				return board[i][j + 2];  
			}
		}
	}

	//dogfall
	if (IsFull(board, row, col)) {
		return 'Q';
	}

	return 'C';
}

