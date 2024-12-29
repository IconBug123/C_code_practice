#define _CRT_SECURE_NO_WARNINGS

#include "game.h"


int main() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("Select.......:>");
		scanf("%d", &input);
		switch (input) {
			case 1:
				//printf("Game Start\n");
				game();
				break;
			case 0:
				printf("Exit Game........\n");
				break;
			default:
				printf("Choose Item\n");
				break;
		}
	} while (input);
	return 0;
}