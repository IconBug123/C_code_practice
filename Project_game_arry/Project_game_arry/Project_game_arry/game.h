#ifndef GAME_HEAD

#define GAME_HEAD
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 5
#define COL 5
/**
* @brief	To initialize the board
*/
void InitBoard(char board[ROW][COL], int row, int col);
	
/**
* @brief	To diplay the board of game 
*/
void DisplayBoard(char board[ROW][COL], int row, int col);

/**
* @brief	Player operation
*/
void PlayerMove(char board[ROW][COL],int row, int col);

/**
* @brief	Computer operation
*/
void ComputerMove(char board[ROW][COL], int row, int col);

/**
* @brief	Checking the result of game (win or defeated)
*/
char IsWin(char board[ROW][COL], int row, int col);

#endif
