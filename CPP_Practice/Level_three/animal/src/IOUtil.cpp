#include "IOUtil.h"
#include <iostream>
#include <limits>

int readInt(const std::string& prompt, int lo, int hi) {
    std::cout << prompt;
    int x;
    while (!(std::cin >> x) || x < lo || x > hi) {
        std::cout << "无效输入，请输入 " << lo << "-" << hi << "：";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return x;
}

std::string readLine(const std::string& prompt) {
    std::cout << prompt;
    std::string s;
    std::getline(std::cin, s);
    return s;
}

bool readYesNo(const std::string& prompt) {
    while (true) {
        std::string s = readLine(prompt + " (y/n): ");
        if (s == "y" || s == "Y") return true;
        if (s == "n" || s == "N") return false;
        std::cout << "请输入 y 或 n\n";
    }
}
