#include "Bin.h"
#include "Vector3D.h"
#include <iostream>

/*
	METHOD DESCRIPTIONS CAN BE FOUND IN Bin.h

	<Summary> .cpp file for Class Bin. Implements methods:
		Bin(int size); 
		~Bin();
		Bin(const Bin& other);
		Bin& operator = (const Bin& other);
		float getX(int a) const;
		float getY(int a) const;
		float getZ(int a) const;
		Vector3D** getArray() const;
		
		void add(float x, float y, float z);
		void remove(int b);
*/

Bin::Bin(int size) {
	this->m_Counter = 0;
	this->m_MaxSize = size;
	this->m_Array = new Vector3D*[size];
}

Bin::~Bin() {
	delete[] this->m_Array;
	this->m_Array = nullptr;
}

Bin::Bin(const Bin& other) {
	m_Counter = other.m_Counter;
	m_MaxSize = other.m_MaxSize;
	m_Array = new Vector3D*[other.m_MaxSize];
	
	memcpy(m_Array, other.m_Array, sizeof(Vector3D*) * m_MaxSize); 	// used memcopy to be more efficient then a for loop for this task.
}

Bin& Bin::operator = (const Bin& other) {
	if (this == &other)
		return *this;

	m_Counter = other.m_Counter;
	m_MaxSize = other.m_MaxSize;
	m_Array = new Vector3D*[other.m_MaxSize];

	memcpy(m_Array, other.m_Array, sizeof(Vector3D*) * m_MaxSize);
	return *this;
}

float Bin::getX(int a) const {
	if (a < this->m_Counter)
		return this->m_Array[a]->getX();
	else
		std::cout << "INVALID ELEMENT: Could not getX()" << std::endl;
}

float Bin::getY(int a) const {
	if (a < this->m_Counter)
		return this->m_Array[a]->getY();
	else
		std::cout << "INVALID ELEMENT: Could not getY()" << std::endl;
}

float Bin::getZ(int a) const {
	if (a < this->m_Counter)
		return this->m_Array[a]->getZ();
	else
		std::cout << "INVALID ELEMENT: Could not getZ()" << std::endl;
}

Vector3D** Bin::getArray() const {
	return this->m_Array;
}

void Bin::add(float x, float y, float z) {
	if (this->m_Counter == m_MaxSize) {
		this->m_MaxSize*= 2;
		Vector3D** temp = new Vector3D*[this->m_MaxSize];

		for (int i = 0; i < this->m_Counter; i++)
			temp[i] = this->m_Array[i];

		this->m_Array = nullptr;
		this->m_Array = temp;

	}
	this->m_Array[this->m_Counter++] = new Vector3D(x, y, z);
}

void Bin::remove(int b) {
	for (int i = b; i < this->m_MaxSize - 1; i++) {
		if (this->m_Array[i + 1] == NULL) {
			this->m_Array[i] = nullptr;
		} else {
			this->m_Array[i] = this->m_Array[i + 1];
		}
	}

	this->m_Counter--;
	this->m_MaxSize--;
}