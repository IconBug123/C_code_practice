#ifndef GAME_HEAD
#define GAME_HEAD

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

//��ʾ����Ϸ�����С
#define ROW 12
#define COL 12

//����Ĵ�С
#define ROWS (ROW+2)
#define COLS (COL+2)

//���׳̶�	���õ�������
#define LEVEL_COUNT 8


/**
*@brief game manu shows the selection of start and exit
*/
void menu();

/**
* @brief ��ʼ������->��ʼ�����������Ϊָ��������
*/
void InitBoard(char mine[ROWS][COLS], int rows, int cols);

/**
* @brief ���õ���λ��
*/
void SetMine(char board[ROWS][COLS], int row, int col);

/**
* @brief ��ʾ����(���ף����Ų�������)
*/
void DisplayBoard(char board[ROWS][COLS], int row, int col);

/**
* @brief �Ų������
*/
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);

/**
* @brief ��ʾ��Χ��������
*/
int GetMineNum(char mine[ROWS][COLS], int row, int col, int x, int y);

/**
* @brief ����Ų����Χû�е����򲻶�չ����Χ��ֱ�����ֵ���
*/
void ExpansionMap(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col, int x, int y);

/**
* @brief ��Ϸ������������Ϸ
*/
void game();

#endif

