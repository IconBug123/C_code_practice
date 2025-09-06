//#pragma once
#ifndef ADDRESSBOOK_HEAD
#define ADDRESSBOOK_HEAD

#include <string>
#include <vector>
#include <unordered_set>

struct Contact {
    std::string name;
    std::string phone;
    std::string address;

    Contact() = default;
    Contact(std::string n, std::string p, std::string a);

    void show() const;
};


class AddressBook {
private:
    std::vector<Contact> contacts;
    using Iter = std::vector<Contact>::iterator;
    using CIter = std::vector<Contact>::const_iterator;

    Iter  findByNameIter(const std::string& key);
    CIter findByNameIter(const std::string& key) const;
    
    //static std::string makeKey(const Contact& c) {
    //    // 用不会在数据里出现的分隔符拼成唯一键
    //    return c.name + '\x1F' + c.phone + '\x1F' + c.address;
    //}

    //bool dedupeExact();

public:
    void addContact(const Contact& c);
    bool removeByName(const std::string& name);
    Contact* findByName(const std::string& name);
    const Contact* findByName(const std::string& name) const;
    bool editByName(const std::string& name, const std::string& newPhone, const std::string& newAddr);
    void sortByNameAsc();
    void showAll() const;
    bool saveToFile(const std::string& path, bool append=false) const;
    bool loadFromFile(const std::string& path);

};


#endif