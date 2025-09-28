#include "UI_APP.h"
#include "Util.h"
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "IsoscelesTrapezoid.h"
#include "RegularPolygon.h"
#include "Storage.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <unordered_set>

using namespace std;

UI_APP::~UI_APP() {
    clearAll(); // 退出时释放所有 new 的对象
}

void UI_APP::printMenu() const {
    cout << "\n===== 几何图形计算器 =====\n"
        << "1) 新增 Circle\n"
        << "2) 新增 Rectangle\n"
        << "3) 新增 Triangle\n"
        << "4) 列出全部图形\n"
        << "5) 按面积升序（相等时按周长）\n"
        << "6) 总面积 / 总周长\n"
        << "7) 删除第 i 个图形\n"
        << "8) 清空全部\n"
        << "9) 退出\n"
        << "10) 新增 IsoscelesTrapezoid\n"
        << "11) 新增 RegularPolygon\n"
        << "12) 按名称查找第一个\n"
        << "13) 按名称查找全部\n"
        << "14) 去重（同类型且参数相同只保留一个）\n"
        << "15) 保存到文件\n"
        << "16) 从文件读取并追加\n";
}

void UI_APP::listAll() const {
    if (shapes.empty()) { cout << "（空）\\n"; return; }
    cout << fixed << setprecision(6);
    for (size_t i = 0; i < shapes.size(); ++i) {
        cout << setw(2) << i << ": ";
        shapes[i]->show();
        cout << " | area=" << shapes[i]->area()
            << " | peri=" << shapes[i]->perimeter() << '\\n';
    }
}

void UI_APP::clearAll() {
    for (auto p : shapes) delete p;
    shapes.clear();
}

int UI_APP::findFirstByName(const string& nm) const {
    auto it = find_if(shapes.begin(), shapes.end(),
        [&](Shape* p) { return p->name() == nm; });
    return (it == shapes.end()) ? -1 : int(it - shapes.begin());
}

vector<int> UI_APP::findAllByName(const string& nm) const {
    vector<int> idx;
    for (int i = 0; i < (int)shapes.size(); ++i)
        if (shapes[i]->name() == nm) idx.push_back(i);
    return idx;
}

void UI_APP::dedupe() {                         //去除重复内容
    unordered_set<string> seen;
    auto new_end = remove_if(shapes.begin(), shapes.end(), [&](Shape* p) {
        auto k = p->key();
        if (seen.insert(k).second) return false; // 首次出现，保留
        delete p;                                // 重复，释放
        return true;                             // 移除
        });
    shapes.erase(new_end, shapes.end());
    cout << "去重完成\\n";
}

void UI_APP::run() {
    while (true) {
        printMenu();
        int op = util::readInt("请选择（1-16）：", 1, 16);

        if (op == 1) {
            double r = util::readDouble("输入半径 r：");
            if (r <= 0) {
                cout << "半径需 > 0"; continue; }
                    shapes.push_back(new Circle(r));
                cout << "✅ 已新增 Circle";
            }
            else if (op == 2) {
                double w = util::readDouble("输入宽 w：");
                double h = util::readDouble("输入高 h：");
                if (w <= 0 || h <= 0) {
                    cout << "w,h 需 > 0"; continue; }
                        shapes.push_back(new Rectangle(w, h));
                    cout << "已新增 Rectangle";
                }
                else if (op == 3) {
                    double a = util::readDouble("边 a：");
                    double b = util::readDouble("边 b：");
                    double c = util::readDouble("边 c：");
                    if (!Triangle::valid(a, b, c)) {
                        cout << "三边不合法"; continue; }
                            shapes.push_back(new Triangle(a, b, c));
                        cout << "已新增 Triangle";
                    }
                    else if (op == 4) {
                        listAll();
                    }
                    else if (op == 5) {
                        sort(shapes.begin(), shapes.end(), [](const Shape* A, const Shape* B) {
                            if (!util::eq(A->area(), B->area())) return A->area() < B->area();
                            return A->perimeter() < B->perimeter();
                            });
                        cout << "已按面积/周长排序";
                    }
                    else if (op == 6) {
                        double sumA = 0, sumP = 0;
                        for (auto p : shapes) { sumA += p->area(); sumP += p->perimeter(); }
                        cout << "总面积 = " << sumA << " | 总周长 = " << sumP << '\n';
                    }
                    else if (op == 7) {
                        if (shapes.empty()) {
                            cout << "（空 "; continue; }
                                int i = util::readInt("删除索引 i：", 0, (int)shapes.size() - 1);
                            delete shapes[i];
                            shapes.erase(shapes.begin() + i);
                            cout << "已删除第 " << i << " 个";
                        }
                        else if (op == 8) {
                            clearAll();
                            cout << "已清空";
                        }
                        else if (op == 9) {
                            clearAll();
                            cout << "Bye!"; break;
                        }
                        else if (op == 10) {
                            double A = util::readDouble("上底 a：");
                            double B = util::readDouble("下底 b：");
                            double H = util::readDouble("高 h：");
                            if (!IsoscelesTrapezoid::valid(A, B, H)) {
                                cout << "参数需 > 0"; continue; }
                                    shapes.push_back(new IsoscelesTrapezoid(A, B, H));
                                cout << "已新增 IsoscelesTrapezoid";
                            }
                            else if (op == 11) {
                                int N = util::readInt("边数 n：", 3, 1000000);
                                double S = util::readDouble("边长 s：");
                                if (!RegularPolygon::valid(N, S)) {
                                    cout << "n>=3 且 s>0"; continue; }
                                        shapes.push_back(new RegularPolygon(N, S));
                                    cout << "已新增 RegularPolygon";
                                }
                                else if (op == 12) {
                                    string nm; cout << "输入名称（如 Circle）："; getline(cin, nm); nm = util::trim(nm);
                                    int idx = findFirstByName(nm);
                                    if (idx == -1) cout << "未找到 "; else cout << "第一个索引 = " << idx << "\n";
                                }
                                else if (op == 13) {
                                    string nm; cout << "输入名称（如 Rectangle）："; getline(cin, nm); nm = util::trim(nm);
                                    auto idxs = findAllByName(nm);
                                    if (idxs.empty()) cout << "未找到";
                                    else {
                                        cout << nm << " 索引：";
                                        for (size_t i = 0; i < idxs.size(); ++i) {
                                            if (i) cout << ", ";
                                            cout << idxs[i];
                                        }
                                        cout << ' ';
                                    }
                                }
                                else if (op == 14) {
                                    dedupe();
                                }
                                else if (op == 15) {
                                    string path; cout << "保存到文件："; getline(cin, path); path = util::trim(path);
                                    cout << (storage::saveToFile(path, shapes) ? "已保存" : " 保存失败");
                                }
                                else if (op == 16) {
                                    string path; cout << "从文件读取："; getline(cin, path); path = util::trim(path);
                                    cout << (storage::loadFromFile(path, shapes) ? "已读取" : "读取失败");
                                }
                            }
                        }
