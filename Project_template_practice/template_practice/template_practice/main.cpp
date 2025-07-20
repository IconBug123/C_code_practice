#include "myArray.hpp"

// Printing Function for int
void printIntArray(MyArray<int>& arr) {
	int i;
	for (i = 0; i < arr.getSize(); i++) {
		std::cout << arr[i] << "  " << std::endl;
	}
}

void test_01() {
	MyArray<int> arr1(10);
	int i;
	for (i = 0; i < 10; i++) {
		arr1.push_back(i);
	}
	std::cout << "arra1 is:  " << std::endl;
	printIntArray(arr1);
	std::cout << "Capacity is " << arr1.getCapacity() << std::endl;
	std::cout << "Size is " << arr1.getSize() << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	
	arr1.pop_back();
	printIntArray(arr1);
	std::cout << "Capacity is " << arr1.getCapacity() << std::endl;
	std::cout << "Size is " << arr1.getSize() << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

}

class Person {
public:
	Person() = default;
	Person(std::string name, int age): m_Name(name), m_Age(age){}
	
	std::string getName() {
		return m_Name;
	}
	int getAge() {
		return m_Age;
	}

private:
	std::string m_Name;
	int m_Age;
};

// Printing Function for class
void printClassArray(MyArray<Person>& arr) {
	int i;
	for (i = 0; i < arr.getSize(); i++) {
		std::cout << arr[i].getName() << "    "<<arr[i].getAge() << std::endl;
	}
	if (arr.getSize() == 0 || arr.getCapacity() == 0) std::cout << "None......" << std::endl;
}



void test_02() {
	//creating array;
	MyArray<Person> arr2(10);
	
	Person p1("A1", 11);
	Person p2("A2", 12);
	Person p3("A3", 13);
	Person p4("A4", 14);
	Person p5("A5", 15);

	//Push Data into Array
	arr2.push_back(p1);
	arr2.push_back(p2);
	arr2.push_back(p3);
	arr2.push_back(p4);
	arr2.push_back(p5);

	printClassArray(arr2);
	std::cout << ".........................................................." << std::endl;

	MyArray<Person> arr3(std::move(arr2));
	printClassArray(arr3);
	printClassArray(arr2);

	MyArray<Person> arr4(10);
	arr4 = std::move(arr3);
	printClassArray(arr4);
	printClassArray(arr3);

}



int main() {
	test_01();
	test_02();
	return 0;
}