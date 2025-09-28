#include "ConsoleUI.h"
#include "IOUtil.h"
#include "Dog.h"
#include "Cat.h"
#include "Bird.h"
#include <algorithm>
#include <iostream>

ConsoleUI::~ConsoleUI() {
    clearAll(); // 释放所有裸指针
}

void ConsoleUI::printMenu() const {
    std::cout << "\n===== 动物叫声模拟器 =====\n"
        << "1) 新增动物\n"
        << "2) 列出全部\n"
        << "3) 让所有动物叫\n"
        << "4) 按类型统计数量\n"
        << "5) 删除第 i 个\n"
        << "6) 清空全部\n"
        << "7) 退出\n";
}

void ConsoleUI::addAnimal() {
    std::cout << "\n可选类型：Dog / Cat / Bird\n";
    std::string kind = readLine("输入类型：");
    std::transform(kind.begin(), kind.end(), kind.begin(),
        [](unsigned char c) { return static_cast<char>(std::tolower(c)); });

    if (kind == "dog") {
        std::string name = readLine("狗的名字：");
        int age = readInt("狗的年龄（0-50）：", 0, 50);
        zoo.push_back(new Dog(name, age));
        std::cout << "已添加\n";

    }
    else if (kind == "cat") {
        std::string name = readLine("猫的名字：");
        std::string color = readLine("毛色：");
        zoo.push_back(new Cat(name, color));
        std::cout << "已添加\n";

    }
    else if (kind == "bird") {
        std::string species = readLine("鸟的品种：");
        bool canTalk = readYesNo("会学人说话吗");
        zoo.push_back(new Bird(species, canTalk));
        std::cout << "已添加\n";

    }
    else {
        std::cout << "未知类型。\n";
    }
}

void ConsoleUI::listAll() const {
    if (zoo.empty()) { std::cout << "（空）\n"; return; }
    for (size_t i = 0; i < zoo.size(); ++i) {
        std::cout << std::setw(2) << i << ": ";
        zoo[i]->show();
        std::cout << '\n';
    }
}

void ConsoleUI::speakAll() const {
    if (zoo.empty()) { std::cout << "（空）\n"; return; }
    for (auto* p : zoo) p->speak();
}

void ConsoleUI::countByType() const {
    if (zoo.empty()) { std::cout << "（空）\n"; return; }
    std::map<std::string, int> cnt;
    for (auto* p : zoo) ++cnt[p->type()];
    for (auto& kv : cnt) std::cout << kv.first << ": " << kv.second << '\n';
}

void ConsoleUI::deleteByIndex() {
    if (zoo.empty()) { std::cout << "（空）\n"; return; }
    int i = readInt("删除索引 i：", 0, static_cast<int>(zoo.size()) - 1);
    delete zoo[static_cast<size_t>(i)];
    zoo.erase(zoo.begin() + i);
    std::cout << "已删除\n";
}

void ConsoleUI::clearAll() {
    for (auto* p : zoo) delete p;
    zoo.clear();
    // 注意：本函数被析构调用时不需要打印提示；手动清空可以在外层打印。
}

namespace {
    enum MenuOption {
        ADD_ANIMAL = 1,
        LIST_ALL,
        SPEAK_ALL,
        COUNT_BY_TYPE,
        DELETE_BY_INDEX,
        CLEAR_ALL,
        EXIT
    };
}

void ConsoleUI::run() {
    while (true) {
        printMenu();
        int op = readInt("请选择（1-7）：", ADD_ANIMAL, EXIT);

        switch (op) {
        case ADD_ANIMAL:
            addAnimal();
            break;
        case LIST_ALL:
            listAll();
            break;
        case SPEAK_ALL:
            speakAll();
            break;
        case COUNT_BY_TYPE:
            countByType();
            break;
        case DELETE_BY_INDEX:
            deleteByIndex();
            break;
        case CLEAR_ALL:
            clearAll();
            std::cout << "已清空\n";
            break;
        case EXIT:
            std::cout << "Bye!\n";
            return; // 或 break 出 while
        default:
            std::cout << "无效选项\n";
        }
    }
}
