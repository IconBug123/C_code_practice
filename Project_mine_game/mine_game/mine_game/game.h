#ifndef GAME_HEAD
#define GAME_HEAD

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

//显示的游戏界面大小
#define ROW 12
#define COL 12

//数组的大小
#define ROWS (ROW+2)
#define COLS (COL+2)

//难易程度	设置地雷数量
#define LEVEL_COUNT 8


/**
*@brief game manu shows the selection of start and exit
*/
void menu();

/**
* @brief 初始化函数->初始化数组的内容为指定的内容
*/
void InitBoard(char mine[ROWS][COLS], int rows, int cols);

/**
* @brief 设置地雷位置
*/
void SetMine(char board[ROWS][COLS], int row, int col);

/**
* @brief 显示数组(地雷，和排查地雷情况)
*/
void DisplayBoard(char board[ROWS][COLS], int row, int col);

/**
* @brief 排查雷情况
*/
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);

/**
* @brief 显示周围地雷数量
*/
int GetMineNum(char mine[ROWS][COLS], int row, int col, int x, int y);

/**
* @brief 如果排查点周围没有地雷则不断展开周围，直到发现地雷
*/
void ExpansionMap(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col, int x, int y);

/**
* @brief 游戏函数，运行游戏
*/
void game();

#endif

