#define _CRT_SECURE_NO_WARNINGS
#include "game.h"


void menu() {
	printf("*************   GAME   **************\n");
	printf("********* 1. paly     0. exit  *********\n");
	printf("************************************\n");
}

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set) {
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			board[i][j] = set;
		}
	}
}

void SetMine(char board[ROWS][COLS], int row, int col) {
	int count = LEVEL_COUNT;
	while (count) {
		int x = rand() % row+1;    //�������x, y
		int y = rand() % col + 1;
		
		if (board[x][y] == '0') {
			board[x][y] = '1';
			count--;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col) {
	int i = 0;
	int j = 0;
	//��ʾtitle
	for (i = 0; i < row; i++) {		
		printf("---", i + 1);
		if (i == (row / 2-1)) {
			printf("   ɨ��   ");
		}
	}
	printf("\n");

	//��ʾ�Ϸ�����ֵ
	printf("    ");
	for (i = 0; i <row; i++) {		//show the number of each colume
		printf(" %d  ", i + 1);
	}
	printf("\n");

	//��ʾ�Ϸ�����ֵ����ķָ���-----
	printf("   ");
	for (i = 0; i < row; i++) {		//show -----------
		printf("----", i + 1);
	}
	printf("-\n");

	//��ʾ���̵ı߿������������꣬���������
	for (i = 1; i <= row; i++) {				
		if (i > 9) {									//show the number of each row
			printf("%d |", i);
		}
		else {
			printf("%d  |", i);
		}
		for (j = 1; j <= col; j++) {
			printf(" %c |", board[i][j]);
		}
		printf("\n");
		
		for (j = 1; j <=col; j++) {		//print  ---�����ָ�ÿһ��
			if (j == 1) {
				printf("   |---|");
			}
			else {
				printf("---|");
			}
		}
		printf("\n");
	}
}

//int GetMineNum(char mine[ROWS][COLS], int x, int y) {
//	//��ASII����� '1' = 49  '0' = 48
//	return (mine[x - 1][y] +
//		mine[x - 1][y - 1] +
//		mine[x - 1][y + 1] +
//		mine[x + 1][y + 1] +
//		mine[x + 1][y] +
//		mine[x + 1][y - 1] +
//		mine[x][y + 1] +
//		mine[x][y - 1] - 8*'0');
//}

int GetMineNum(char mine[ROWS][COLS], int row, int col, int x, int y) {
	int count = 0;
	// ������Χ 8 ������
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == 0 && j == 0) continue; // ��������
			int nx = x + i;
			int ny = y + j;
			// ��������Ƿ�Խ��
			if (nx >= 1 && nx <= row && ny >= 1 && ny <= col) {
				if (mine[x + i][y + j] == '1') { // ���� '1' ��ʾ����
					count++;
				}
			}
		}
	}
	return count;
}

void ExpansionMap(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col, int x, int y) {
	if (x < 1 || x > row || y < 1 || y > col || show[x][y] != '*'){
		// Խ����Ѵ���ĸ���ֱ�ӷ���
		return;
	}
	int count = GetMineNum(mine, ROW, COL,x, y);
	if (count > 0) {
		// ��ǰ������Χ�е��ף���ʾ��������
		show[x][y] = '0' + count;
	}
	else {
		// ��ǰ������Χ�޵��ף�չ��
		show[x][y] = ' ';
	
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i != 0 || j != 0) { // ������ǰ����
					ExpansionMap(show, mine, row, col, x + i, y + j);
				}
			}
		}
	}
}

//void ExpansionMap(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col, int x, int y) {
//	//int count = GetMineNum(mine, x, y);
//	if (GetMineNum(mine, row, col, x, y) == 0) {
//		show[x][y] = ' ';
//		int i = 0;
//		int j = 0;
//		for (i = -1; i < 2; i++) {
//			for (j = -1; j < 2; j++) {
//				
//				if(x+i < 1 || x+i > row || y +j< 1 || y+j > col || show[x+i][y+j] != '*'){  //Error ����Ǳ߻���������ͻ�return����
//					return;
//				}
//				else {
//					if (i != 0 || j != 0) {
//						ExpansionMap(show, mine, row, col, x + i, y + j);
//					}
//				}
//			}
//		}
//	}
//
//	else {
//		show[x][y] = '0' + GetMineNum(mine, row, col, x, y);
//	}
//}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x = 0;
	int y = 0;
	int win = 0;

	while (win!=LEVEL_COUNT) {
		printf("Please input the coordinator:> ");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (mine[x][y] == '1') {
				system("cls");
				printf("!!!!�㱻ը���� (You are dead!!!!)\n\n");
				DisplayBoard(mine, ROW, COL);
				printf("\n\n");
				break;
			}
			else if (show[x][y] != '*') {
				printf("�õ����Ų飬�������µ�����.......\n");
			}
			else {
				system("cls");
				ExpansionMap(show, mine, ROW, COL, x, y);
				//show[x][y] = count + '0';
				win = 0;
				for (int i = 1; i <= row; i++) {
					for (int j = 1; j <= col; j++) {
						if (show[i][j] == '*') {
							win++;
						}
					}
				}
				//DisplayBoard(mine, ROW, COL);
				DisplayBoard(show, ROW, COL);
			}
		}
		else {
			printf("Your input is error...Please input again...\n");
		}
	}
	if (win == LEVEL_COUNT) {
		system("cls");
		printf("\n������ʤ����������Successful��������\n\n");
		DisplayBoard(mine, ROW, COL);
		printf("\n\n");
	}
	
}

void game() {
	char mine[ROWS][COLS] = { 0 };   //��Ų��úõ��׵���Ϣ
	char show[ROWS][COLS] = { 0 };	//����Ų���׵���Ϣ,
	//��ʼ�����������Ϊָ��������
	//mine������û�в����׵�ʱ�򣬶��� '0'
	//show������û���Ų��׵�ʱ�򣬶��� '*'
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS, '*');
	
	//���õ���λ��
	SetMine(mine, ROW, COL);

	//��ʾ��ʼʱ����Ϸ����
	system("cls");
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//�Ų��ף���ʾ��Χ�׵ĸ���
	FindMine(mine, show, ROW, COL);

}


//��߸���
/*
* 1��ǹ��� (��ǿ���λ��)   δ���
* 2չ��һƬ  ��
*/