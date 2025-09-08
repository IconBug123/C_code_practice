#include <iostream>
#include "UI_APP.h"


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	UI_APP app; // 封装了 UI 交互与业务逻辑
	app.run(); // 进入主循环

	return 0;
}

