#include "Vector3D.h"
#include <iostream>
#include "assert.h"

int main(void) {

	Vector3D vector1(1, 2, 2);
	Vector3D vector2(-1, 2, 2);
	Vector3D vector3(2, 1, 1);
	Vector3D vector4(5, 5, 5);

	// PART I 
	std::cout << "PART I: 'return an x,y or z  component of a vector'" << std::endl;
	std::cout << "TEST 1: get_z()" << std::endl;
	assert(vector1.get_x() == 1);

	std::cout << "TEST 2: get_z()" << std::endl;
	assert(vector1.get_y() == 2);

	std::cout << "TEST 3: get_z()" << std::endl;
	assert(vector1.get_z() == 2);
	std::cout << "" << std::endl;


	// PART II
	std::cout << "PART II: 'compute the magnitude of a vector'" << std::endl;
	std::cout << "TEST 4: find_Magnitude()" << std::endl;
	assert(vector1.find_Magnitude() == 3);
	// Testing for negative Magnitude.
	assert(vector2.find_Magnitude() == 3);

	std::cout << "" << std::endl;



	// PART III
	std::cout << "PART III: 'operators to add, and subtract vectors'" << std::endl;
	std::cout << "TEST 5: add_V3D()" << std::endl;
	vector1.add_V3D(vector3);
	assert(vector1.get_x() == 3);
	assert(vector1.get_y() == 3);
	assert(vector1.get_z() == 3);

	std::cout << "TEST 6: sub_V3D()" << std::endl;
	vector1.sub_V3D(vector3);
	assert(vector1.get_x() == 1);
	assert(vector1.get_y() == 2);
	assert(vector1.get_z() == 2);
	std::cout << "" << std::endl;


	// PART IV
	std::cout << "PART IV: 'operators to multiply and divide a vector by a scalar'" << std::endl;
	std::cout << "TEST 7: mult_V3D()" << std::endl;
	vector1.mult_V3D(2);
	assert(vector1.get_x() == 2);
	assert(vector1.get_y() == 4);
	assert(vector1.get_z() == 4);

	std::cout << "TEST 8: div_V3D()" << std::endl;
	vector1.div_V3D(2);
	assert(vector1.get_x() == 1);
	assert(vector1.get_y() == 2);
	assert(vector1.get_z() == 2);
	std::cout << "" << std::endl;


	// PART V
	std::cout << "PART V: 'calculate the scalar and vector product of two vectors'" << std::endl;
	std::cout << "TEST 9: dot_Prod_V3D()" << std::endl;
	float f1 = vector1.dot_Prod_V3D(vector4);
	assert(f1 == 25);

	std::cout << "TEST 10: dot_Prod_V3D()" << std::endl;
	Vector3D vector5 = vector1.cross_Prod_V3D(vector4);
	assert(vector5.get_x() == 0);
	assert(vector5.get_y() == 5);
	assert(vector5.get_z() == -5);
	std::cout << "" << std::endl;


	// PART VI
	std::cout << "PART VI: 'overload other operators to allow sensible expressions of vectors to be written (Use operator* for scalar product and operator% for vector product)'" << std::endl;
	std::cout << "TEST 11: operator += ()" << std::endl;
	vector1 += vector3;
	assert(vector1.get_x() == 3);
	assert(vector1.get_y() == 3);
	assert(vector1.get_z() == 3);

	std::cout << "TEST 12: operator -= ()" << std::endl;
	vector1 -= vector3;
	assert(vector1.get_x() == 1);
	assert(vector1.get_y() == 2);
	assert(vector1.get_z() == 2);
	
	std::cout << "TEST 13: operator * ()" << std::endl;
	float f2 = vector1 * vector4;
	assert(f2 == 25);

	std::cout << "TEST 14: operator % ()" << std::endl;
	Vector3D vector6 = vector1 % vector4;
	assert(vector6.get_x() == 0);
	assert(vector6.get_y() == 5);
	assert(vector6.get_z() == -5);
	std::cout << "" << std::endl;

	// PART VII
	std::cout << "PART VII: 'produce a unit vector (one of magnitude 1) pointing in the same direction as a given vector'" << std::endl;

	// Part VIII
	std::cout << "'return a unit vector orthogonal to two given vectors.'" << std::endl;
	return 0;
}