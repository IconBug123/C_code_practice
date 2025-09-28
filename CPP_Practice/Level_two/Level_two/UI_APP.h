#ifndef UI_APP_HEAD
#define UI_APP_HEAD

#include <string>
#include <vector>

class Shape;

class UI_APP {
public:
    UI_APP() = default;
    ~UI_APP();                 // 负责释放内部原生指针
    void run();                // 入口（菜单主循环）

private:
    std::vector<Shape*> shapes;  // 原生指针容器

    // UI & 业务
    void printMenu() const;
    void listAll() const;
    void clearAll();
    int  findFirstByName(const std::string& nm) const;
    std::vector<int> findAllByName(const std::string& nm) const;
    void dedupe();
};





#endif
