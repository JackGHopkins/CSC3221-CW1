#include "Vector3D.h"
#pragma once

class Bin {
private:
	int m_Counter;
	int m_MaxSize;
	Vector3D** m_Array;
public:
	Bin(int size);
	~Bin();
	Bin(const Bin& other);
	float getX(int a) const;
	float getY(int a) const;
	float getZ(int a) const;
	Vector3D** getArray() const;
	
	void add(float x, float y, float z);
	void remove(int b);
	
};