#include "Vector3D.h"
#pragma once

class Bin {
private:
	int m_size;
	Vector3D** m_Array;
public:
	Bin(int a);
	~Bin();
	Bin(const Bin& other);
	float getX(int a) const;
	float getY(int a) const;
	float getZ(int a) const;
	
	void add(float x, float y, float z);
	void remove(int b);
	
};