//#pragma once
#ifndef APPUI_HEAD
#define APPUI_HEAD

#include "AddressBook.h"

class AppUI {
public:
    static void run();  // Ψһ��¶�����
private:
    //����
    static std::string readLine(const std::string& prompt);   //������Ϣ�Ĺ���
    static int readMenuChoice();    //ʶ���������Ĺ���
    static void printMenu();          //��ʾ����Ĺ���
};

#endif