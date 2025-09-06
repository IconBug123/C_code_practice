#include "AppUI.h"
#include <iostream>
#include <limits>

using namespace std;

string AppUI::readLine(const string& prompt) {
    cout << prompt;
    string s;
    getline(cin, s);
    return s;
}

int AppUI::readMenuChoice() {
    cout << "\n请选择操作（1-9）：";
    int op = 0;
    while (true) {
        if (cin >> op && op >= 1 && op <= 9) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    //清除空格后面的所有内容直到\n (包括\n)
            return op;
        }
        cout << "输入无效，请输入 1-9：";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void AppUI::printMenu() {
    cout << "\n====== 通讯录菜单 ======\n"
        << "1) 添加联系人\n"
        << "2) 删除联系人（按姓名）\n"
        << "3) 修改联系人（按姓名）\n"
        << "4) 查找联系人（按姓名）\n"
        << "5) 显示所有联系人\n"
        << "6) 按姓名排序（升序）\n"
        << "7) 保存到文件\n"
        << "8) 从文件加载\n"
        << "9) 退出\n";
}

void AppUI::run() {
    ios::sync_with_stdio(false);  //关闭C语言的printf和C++的同步，提高性能
    cin.tie(nullptr);    //关闭输出的刷新，从而在输入时提高性能

    //人为添加几个信息，便于测试
    AddressBook book;                                                      // has-a结构
    book.addContact({ "张三", "123456", "北京" });
    book.addContact({ "李四", "987654", "上海" });
    book.addContact({ "王五", "555555", "广州" });

    while (true) {
        printMenu();
        int op = readMenuChoice();
        if (op == 1) {
            string name = readLine("姓名：");
            string phone = readLine("电话：");
            string addr = readLine("地址：");
            book.addContact({ name, phone, addr });
            cout << "已添加\n";
        }
        else if (op == 2) {
            string name = readLine("输入要删除的姓名：");
            if (book.removeByName(name)) cout << "已删除\n";
            else cout << "未找到该联系人\n";
        }
        else if (op == 3) {
            string name = readLine("输入要修改的姓名：");
            string newPhone = readLine("新电话（留空则不改）：");
            string newAddr = readLine("新地址（留空则不改）：");
            if (book.editByName(name, newPhone, newAddr)) cout << "已修改\n";
            else cout << " 未找到该联系人\n";
        }
        else if (op == 4) {
            string name = readLine("输入要查找的姓名：");
            const Contact* p = book.findByName(name);
            if (p) p->show();
            else cout << "未找到该联系人\n";
        }
        else if (op == 5) {
            book.showAll();
        }
        else if (op == 6) {
            book.sortByNameAsc();
            cout << "已按姓名排序（升序）\n";
        }
        else if (op == 7) {
            string path = readLine("保存文件名（例如 contacts.txt）：");

            cout << "选择保存模式：\n"
                << "1) 覆盖保存（清空原文件再写入）\n"
                << "2) 追加保存（在原文件末尾添加）\n";
            int mode = readMenuChoice();

            bool append = (mode == 2);
            if (book.saveToFile(path, append)) cout << "已保存\n";
            else cout << "保存失败\n";
        }
        else if (op == 8) {
            string path = readLine("加载文件名（例如 contacts.txt）：");
            if (book.loadFromFile(path)) cout << "已加载\n";
            else cout << "加载失败\n";
        }
        else if (op == 9) {
            cout << "Bye!\n";
            break;
        }
    }
}
