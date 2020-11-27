#include "Vector3D.h"
#pragma once

/*
	<Summary>
		Private:
			int m_Counter: a variable which records the number of Vector3D*s currently in the m_Array.
			int m_MaxSize: a variable which records the current Size of the Array.
			Vector3D** m_Array: a pointer to an array of pointers of Vector3D objects.

		Prublic:
			Bin(int size):							Constructor with takes an int parameter which dictates how many Vector3D**s can fit in the Array.
			~Bin():									Destructor for Bin Objects.
			Bin(const Bin& other):					Copy Constructor for Class Bin.
			Bin& operator = (const Bin& other):		Overloaded Assignment Operator
			
			float getX(int a) const, 
			float getY(int a) const, 
			float getZ(int a) const:				Each accepts int a parameter and return x, y, and z components for the ath element respectively.					
			
			Vector3D** getArray() const:			Gets Array from Bin.
			
			void add(float x, float y, float z):	Accepts floats x, y and z. Adds a new element with those values to the bin at the end, extending
													 the allocated memory if necessary.
			
			void remove(int b):						Accepts an int b, deletes the b'th element of the bin. Shunts all the subsequent elements to fill
													the gap
			*/

class Bin {
private:
	int m_Counter;
	int m_MaxSize;
	Vector3D** m_Array;
public:
	Bin(int size);
	~Bin();
	Bin& operator = (const Bin& other);
	Bin(const Bin& other);
	float getX(int a) const;
	float getY(int a) const;
	float getZ(int a) const;
	Vector3D** getArray() const;
	
	void add(float x, float y, float z);
	void remove(int b);
	
};