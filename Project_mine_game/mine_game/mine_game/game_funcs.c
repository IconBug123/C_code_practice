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
		int x = rand() % row+1;    //随机坐标x, y
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
	//显示title
	for (i = 0; i < row; i++) {		
		printf("---", i + 1);
		if (i == (row / 2-1)) {
			printf("   扫雷   ");
		}
	}
	printf("\n");

	//显示上方坐标值
	printf("    ");
	for (i = 0; i <row; i++) {		//show the number of each colume
		printf(" %d  ", i + 1);
	}
	printf("\n");

	//显示上方坐标值下面的分割线-----
	printf("   ");
	for (i = 0; i < row; i++) {		//show -----------
		printf("----", i + 1);
	}
	printf("-\n");

	//显示棋盘的边框，左侧的数字坐标，和相关内容
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
		
		for (j = 1; j <=col; j++) {		//print  ---用来分割每一行
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
//	//是ASII码相加 '1' = 49  '0' = 48
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
	// 遍历周围 8 个方向
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == 0 && j == 0) continue; // 跳过自身
			int nx = x + i;
			int ny = y + j;
			// 检查坐标是否越界
			if (nx >= 1 && nx <= row && ny >= 1 && ny <= col) {
				if (mine[x + i][y + j] == '1') { // 假设 '1' 表示地雷
					count++;
				}
			}
		}
	}
	return count;
}

void ExpansionMap(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col, int x, int y) {
	if (x < 1 || x > row || y < 1 || y > col || show[x][y] != '*'){
		// 越界或已处理的格子直接返回
		return;
	}
	int count = GetMineNum(mine, ROW, COL,x, y);
	if (count > 0) {
		// 当前格子周围有地雷，显示地雷数量
		show[x][y] = '0' + count;
	}
	else {
		// 当前格子周围无地雷，展开
		show[x][y] = ' ';
	
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i != 0 || j != 0) { // 跳过当前格子
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
//				if(x+i < 1 || x+i > row || y +j< 1 || y+j > col || show[x+i][y+j] != '*'){  //Error 如果是边或角则上来就会return结束
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
				printf("!!!!你被炸死了 (You are dead!!!!)\n\n");
				DisplayBoard(mine, ROW, COL);
				printf("\n\n");
				break;
			}
			else if (show[x][y] != '*') {
				printf("该点已排查，请输入新的坐标.......\n");
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
		printf("\n！！！胜利！！！（Successful！！！）\n\n");
		DisplayBoard(mine, ROW, COL);
		printf("\n\n");
	}
	
}

void game() {
	char mine[ROWS][COLS] = { 0 };   //存放布置好的雷的信息
	char show[ROWS][COLS] = { 0 };	//存放排查出雷的信息,
	//初始化数组的内容为指定的内容
	//mine数组在没有布置雷的时候，都是 '0'
	//show数组在没有排查雷的时候，都是 '*'
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS, '*');
	
	//设置地雷位置
	SetMine(mine, ROW, COL);

	//显示开始时的游戏界面
	system("cls");
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//排查雷，提示周围雷的个数
	FindMine(mine, show, ROW, COL);

}


//提高改善
/*
* 1标记功能 (标记可疑位置)   未完成
* 2展开一片  √
*/