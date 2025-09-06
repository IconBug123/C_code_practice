#include "AddressBook.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

Contact::Contact(std::string n, std::string p, std::string a)
    : name(std::move(n)), phone(std::move(p)), address(std::move(a)) {}

void Contact::show() const {
    cout << "����: " << name
        << " | �绰: " << phone
        << " | ��ַ: " << address << '\n';
}

AddressBook::Iter AddressBook::findByNameIter(const string& key) {
    return find_if(contacts.begin(), contacts.end(),
        [&](const Contact& c) { return c.name == key; });
}

AddressBook::CIter AddressBook::findByNameIter(const string& key) const {
    return find_if(contacts.cbegin(), contacts.cend(),
        [&](const Contact& c) { return c.name == key; });
}

void AddressBook::addContact(const Contact& c) {
    contacts.push_back(c);
}

bool AddressBook::removeByName(const string& name) {
    auto it = findByNameIter(name);
    if (it == contacts.end()) return false;
    contacts.erase(it);
    return true;
}

Contact* AddressBook::findByName(const string& name) {
    auto it = findByNameIter(name);
    return it == contacts.end() ? nullptr : &*it;
}

const Contact* AddressBook::findByName(const string& name) const {
    auto it = findByNameIter(name);
    return it == contacts.end() ? nullptr : &*it;
}

bool AddressBook::editByName(const string& name, const string& newPhone, const string& newAddr) {
    if (auto* p = findByName(name)) {
        if (!newPhone.empty()) p->phone = newPhone;
        if (!newAddr.empty())  p->address = newAddr;
        return true;
    }
    return false;
}

void AddressBook::sortByNameAsc() {
    sort(contacts.begin(), contacts.end(),
        [](const Contact& a, const Contact& b) {
            return a.name < b.name;
        });
}

void AddressBook::showAll() const {
    if (contacts.empty()) {
        cout << "���գ�\n";
        return;
    }
    cout << "���� ͨѶ¼ ����\n";
    for (const auto& c : contacts) c.show();
}

bool AddressBook::saveToFile(const string& path, bool append) const {
    std::ios::openmode mode = std::ios::out;
    if (append) {
        mode |= std::ios::app;   // ׷��ģʽ
    }
    else {
        mode |= std::ios::trunc; // ����ģʽ����ʵĬ�Ͼ��� trunc��������д�ϸ�ֱ�ۣ�
    }
    
    ofstream ofs(path, mode);
    if (!ofs) return false;
    for (const auto& c : contacts)
        ofs << c.name << '\t' << c.phone << '\t' << c.address << '\n';
    return true;
}

//bool AddressBook::dedupeExact() {
//    std::unordered_set<std::string> seen;
//    seen.reserve(contacts.size());
//    std::vector<Contact> out;
//    out.reserve(contacts.size());
//
//    for (const auto& c : contacts) {
//        auto key = makeKey(c);
//        if (seen.insert(key).second) { // �״γ���
//            out.push_back(c);
//        }
//    }
//    bool changed = (out.size() != contacts.size());
//    if(changed) contacts.swap(out);
//    return changed;
//}

bool AddressBook::loadFromFile(const string& path) {
    ifstream ifs(path);
    if (!ifs) return false;

    std::unordered_set<std::string> seen;
    std::vector<Contact> temp;
    temp.reserve(contacts.size()); // ��δ֪���ɲ�д

    string line;

    while (getline(ifs, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.empty()) continue;

        size_t p1 = line.find('\t');
        size_t p2 = (p1 == string::npos) ? string::npos : line.find('\t', p1 + 1);

        if (p1 == string::npos || p2 == string::npos) continue;

        string name = line.substr(0, p1);
        string phone = line.substr(p1 + 1, p2 - p1 - 1);
        string addr = line.substr(p2 + 1);

        // ֱ���ڶ�ȡ�׶�����
        std::string key;
        key.reserve(name.size() + 1 + phone.size() + 1 + addr.size());
        key.append(name).push_back('\x1F');
        key.append(phone).push_back('\x1F');
        key.append(addr);

        if (seen.insert(key).second) {
            temp.emplace_back(std::move(name), std::move(phone), std::move(addr));    //temp.emplace_back(Contact{ name, phone, addr }); �˴�д�����ȴ���һ����ʱContact����, Ȼ���ٿ��������ƶ���vector��, 
            //��ǰ��д��ֱ����vector��ԭ�ع���һ��, ���Ч�ʸ�
        }
    }
        contacts.swap(temp);
      

    return true;
}

