#pragma once
#include <iostream>
#ifndef HEAD_TEMPLATE
#define HEAD_TEMPLATE

template<typename T>
class MyArray {
public:
	//constructor 
	MyArray(int capacity): 
		m_Capacity(capacity), 
		m_Size(0), 
		pAddress(new T[this->m_Capacity]){}
	
	//Copied constructor
	MyArray(const MyArray& others):
		pAddress(new T[others. m_Capacity]),
		m_Capacity(others.m_Capacity),
		m_Size(others.m_Size)
		{
			int i;
			for (i = 0; i < m_Size; ++i) {
				pAddress[i] = others.pAddress[i];
			}
		}

	// Move constructor
	MyArray(MyArray&& others) noexcept: 
		m_Capacity(others.m_Capacity), m_Size(others.m_Size), pAddress(others.pAddress) {
		others.pAddress = nullptr;
		others.m_Size = 0;
		others.m_Capacity = 0;
	}
	
	//operator=
	MyArray& operator=(const MyArray& others) noexcept {
		if (this == &others) return *this;
			
		delete[] pAddress;
		pAddress = nullptr;
		m_Capacity = others.m_Capacity;
		m_Size = others.m_Size;
		pAddress = new T[m_Capacity];
		
		int i;
		for (i = 0; i < m_Size; ++i) {
			pAddress[i] = others.pAddress[i];
		}
		return *this;
	}
	
	// Move assignment
	MyArray& operator=(MyArray&& other) noexcept {
		if (this == &other) return *this;
		delete[] pAddress;

		m_Capacity = other.m_Capacity;
		m_Size = other.m_Size;
		pAddress = other.pAddress;

		other.pAddress = nullptr;
		other.m_Size = 0;
		other.m_Capacity = 0;
		return *this;
	}

	//operator[]
	T& operator[](int index) noexcept {
		if (index < 0 || index >= m_Size) {
			throw std::out_of_range("Index out of bounds");
		}
		return this->pAddress[index];  //not consider out of the boundary
	}

	//Push Back
	void push_back(const T& val) {
		if (this->m_Capacity == this->m_Size) return;
		this->pAddress[m_Size] = val;
		this->m_Size++;
	}

	//Pop Back
	void pop_back() {
		if (m_Size == 0) return;
		this->m_Size--;
	}
	//show Capacity
	int getCapacity() {
		return this->m_Capacity;
	}

	// show Size
	int getSize() {
		return this->m_Size;
	}

	//deconstructor
	~MyArray() {
		if (pAddress != nullptr) {
			delete[] pAddress;
			pAddress = nullptr;
		} 
		m_Capacity = 0;
		m_Size = 0;
	}

private:
	int m_Capacity;
	int m_Size;
	T* pAddress;
};

#endif