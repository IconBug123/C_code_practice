
#ifndef CONTACT_HEAD
#define CONTACT_HEAD

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

struct Contact {
	std::string name;
	std::string phone;
	std::string address;

	Contact() = default;
	Contact(std::string n, std::string p, std::string a);

	void show() const;
};






#endif // !HEAD
