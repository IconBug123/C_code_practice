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
    ~ConsoleUI();                 // �����ͷ����� Animal*

    void run();                   // ��ѭ��

private:
    std::vector<Animal*> zoo;

    void printMenu() const;
    void addAnimal();             // �����������ʽ��
    void listAll() const;         // �г�ȫ��
    void speakAll() const;        // ���ж����
    void countByType() const;     // ������ͳ��
    void deleteByIndex();         // ɾ���� i ��
    void clearAll();              // ���ȫ��
};

#endif // CONSOLE_UI_H
