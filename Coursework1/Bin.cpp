#include "Bin.h"
#include "Vector3D.h"
#include <iostream>

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
	Vector3D** array = new Vector3D*[other.m_MaxSize];

	for (int i = 0; i < other.m_MaxSize; i++) {
		array[i] = other.m_Array[i];
	}
}

float Bin::getX(int a) const {
	return this->m_Array[a]->getX();
}

float Bin::getY(int a) const {
	return this->m_Array[a]->getY();
}

float Bin::getZ(int a) const {
	return this->m_Array[a]->getZ();
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