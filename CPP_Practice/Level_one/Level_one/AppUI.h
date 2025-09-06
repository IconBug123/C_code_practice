//#pragma once
#ifndef APPUI_HEAD
#define APPUI_HEAD

#include "AddressBook.h"

class AppUI {
public:
    static void run();  // 唯一暴露的入口
private:
    //工具
    static std::string readLine(const std::string& prompt);   //输入信息的工具
    static int readMenuChoice();    //识别输入号码的工具
    static void printMenu();          //显示界面的工具
};

#endif