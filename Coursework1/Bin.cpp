#include "Bin.h"
#include "Vector3D.h"
#include <iostream>

Bin::Bin(int a) {
	this->m_Array = new Vector3D*[a];
	this->m_size = a;

	for (int i = 0; sizeof(this->m_Array); i++) {
		m_Array[i] = nullptr;
	}
}

Bin::~Bin() {
	delete[] m_Array;
	m_Array = nullptr;
}

Bin::Bin(const Bin& other) {
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

void Bin::add(float x, float y, float z) {
	bool space = true;

	Vector3D v(x, y, z);
	Vector3D* vPtr = &v;

	for (int i = 0; 0 < sizeof(this->m_Array); i++) {
		if (this->m_Array[i] == nullptr) {
			this->m_Array[i] = vPtr;
			break;
		}

		if (i + 1 == sizeof(this->m_Array)) {
			space = false;
		}
	}

	if (space == false) {
		Vector3D** temp = new Vector3D*[sizeof(this->m_Array) + 1];
		temp[sizeof(temp)] = vPtr;
		this->m_Array = temp;
	}
}

void Bin::remove(int b) {
	this->m_Array[b] = nullptr;
	Vector3D** temp = new Vector3D * [sizeof(this->m_Array) - 1];

	for (int i = b; i < sizeof(this->m_Array) - 1; i++) {
		m_Array[i] = m_Array[i + 1];
	}

	for (int i = 0; i < sizeof(temp); i++) {
		temp[i] = m_Array[i];
	}
	
	m_Array = temp;
}