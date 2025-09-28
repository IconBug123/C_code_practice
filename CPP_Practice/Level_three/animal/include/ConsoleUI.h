#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include <vector>
#include <string>
#include <map>
#include <iomanip>
#include "Animal.h"

class ConsoleUI {
public:
    ConsoleUI() = default;
    ~ConsoleUI();                 // 负责释放所有 Animal*

    void run();                   // 主循环

private:
    std::vector<Animal*> zoo;

    void printMenu() const;
    void addAnimal();             // 新增动物（交互式）
    void listAll() const;         // 列出全部
    void speakAll() const;        // 所有动物叫
    void countByType() const;     // 按类型统计
    void deleteByIndex();         // 删除第 i 个
    void clearAll();              // 清空全部
};

#endif // CONSOLE_UI_H
