#include <iostream>
#include <string>
#include "head.h"

int main() {
    MyVector<int> v{ 1, 2, 3 };
    v.push_back(4);
    v.push_back(5);

    std::cout << "size=" << v.size() << " cap=" << v.capacity() << "\n";
    for (auto x : v) std::cout << x << ' ';
    std::cout << "\n";

    v.pop_back();
    v.resize(8, 9);

    for (auto x : v) std::cout << x << ' ';
    std::cout << "\n";

    v.reserve(32);
    std::cout << "after reserve: size=" << v.size() << " cap=" << v.capacity() << "\n";
    std::cout << "front=" << v.front() << " back=" << v.back() << "\n";

    try {
        std::cout << v.at(100) << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "catch: " << e.what() << "\n";
    }

    MyVector<std::string> s1{ "a", "bb", "ccc" };
    MyVector<std::string> s2 = s1;        // 拷贝构造
    MyVector<std::string> s3 = std::move(s1); // 移动构造
    s2.push_back("dddd");

    for (auto& s : s2) std::cout << s << ' '; std::cout << "\n";
    for (auto& s : s3) std::cout << s << ' '; std::cout << "\n";
}
