#ifndef UI_APP_HEAD
#define UI_APP_HEAD

#include <string>
#include <vector>

class Shape;

class UI_APP {
public:
    UI_APP() = default;
    ~UI_APP();                 // �����ͷ��ڲ�ԭ��ָ��
    void run();                // ��ڣ��˵���ѭ����

private:
    std::vector<Shape*> shapes;  // ԭ��ָ������

    // UI & ҵ��
    void printMenu() const;
    void listAll() const;
    void clearAll();
    int  findFirstByName(const std::string& nm) const;
    std::vector<int> findAllByName(const std::string& nm) const;
    void dedupe();
};





#endif
