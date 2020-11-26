#include "Vector3D.h"
#include "Bin.h"
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
	assert(vector1.getX() == 1);

	std::cout << "TEST 2: get_z()" << std::endl;
	assert(vector1.getY() == 2);

	std::cout << "TEST 3: get_z()" << std::endl;
	assert(vector1.getZ() == 2);
	std::cout << "" << std::endl;


	// PART II
	std::cout << "PART II: 'compute the magnitude of a vector'" << std::endl;
	std::cout << "TEST 4: find_Magnitude()" << std::endl;
	assert(vector1.findMagnitude() == 3);
	// Testing for negative Magnitude.
	assert(vector2.findMagnitude() == 3);

	std::cout << "" << std::endl;



	// PART III
	std::cout << "PART III: 'operators to add, and subtract vectors'" << std::endl;
	std::cout << "TEST 5: add_V3D()" << std::endl;
	vector1.addV3D(vector3);
	assert(vector1.getX() == 3);
	assert(vector1.getY() == 3);
	assert(vector1.getZ() == 3);

	std::cout << "TEST 6: sub_V3D()" << std::endl;
	vector1.subV3D(vector3);
	assert(vector1.getX() == 1);
	assert(vector1.getY() == 2);
	assert(vector1.getZ() == 2);
	std::cout << "" << std::endl;


	// PART IV
	std::cout << "PART IV: 'operators to multiply and divide a vector by a scalar'" << std::endl;
	std::cout << "TEST 7: mult_V3D()" << std::endl;
	vector1.multV3D(2);
	assert(vector1.getX() == 2);
	assert(vector1.getY() == 4);
	assert(vector1.getZ() == 4);

	std::cout << "TEST 8: div_V3D()" << std::endl;
	vector1.divV3D(2);
	assert(vector1.getX() == 1);
	assert(vector1.getY() == 2);
	assert(vector1.getZ() == 2);
	std::cout << "" << std::endl;


	// PART V
	std::cout << "PART V: 'calculate the scalar and vector product of two vectors'" << std::endl;
	std::cout << "TEST 9: dot_Prod_V3D()" << std::endl;
	float f1 = vector1.dotProdV3D(vector4);
	assert(f1 == 25);

	std::cout << "TEST 10: dot_Prod_V3D()" << std::endl;
	Vector3D vector5 = vector1.crossProdV3D(vector4);
	assert(vector5.getX() == 0);
	assert(vector5.getY() == 5);
	assert(vector5.getZ() == -5);
	std::cout << "" << std::endl;


	// PART VI
	std::cout << "PART VI: 'overload other operators to allow sensible expressions of vectors to be written (Use operator* for scalar product and operator% for vector product)'" << std::endl;
	std::cout << "TEST 11: operator += ()" << std::endl;
	vector1 += vector3;
	assert(vector1.getX() == 3);
	assert(vector1.getY() == 3);
	assert(vector1.getZ() == 3);

	std::cout << "TEST 12: operator -= ()" << std::endl;
	vector1 -= vector3;
	assert(vector1.getX() == 1);
	assert(vector1.getY() == 2);
	assert(vector1.getZ() == 2);
	
	std::cout << "TEST 13: operator * ()" << std::endl;
	float f2 = vector1 * vector4;
	assert(f2 == 25);

	std::cout << "TEST 14: operator % ()" << std::endl;
	Vector3D vector6 = vector1 % vector4;
	assert(vector6.getX() == 0);
	assert(vector6.getY() == 5);
	assert(vector6.getZ() == -5);
	std::cout << "" << std::endl;

	// PART VII
	std::cout << "PART VII: 'produce a unit vector (one of magnitude 1) pointing in the same direction as a given vector'" << std::endl;
	std::cout << "TEST 15: unit_V3D()" << std::endl;
	vector1 = Vector3D(1, 2, 2);
	Vector3D vector1Unit = vector1.unitV3D();
	float mag = vector1.findMagnitude();
	assert(vector1Unit.getX() == (1 / mag));
	assert(vector1Unit.getY() == (2 / mag));
	assert(vector1Unit.getZ() == (2 / mag));
	std::cout << "" << std::endl;

	// Part VIII
	std::cout << "PART VIII :'return a unit vector orthogonal to two given vectors.'" << std::endl;
	std::cout << "TEST 16: unit_Orthoganal_V3D()" << std::endl;
	Vector3D vector1UnitOrth = vector1.unitOrthoganalV3D(vector4);
	mag = (vector1.crossProdV3D(vector4)).findMagnitude();
	assert(vector1UnitOrth.getX() == (0 / mag));
	assert(vector1UnitOrth.getY() == (5 / mag));
	assert(vector1UnitOrth.getZ() == (-5 / mag));
	std::cout << "" << std::endl;

	// Part IX
	std::cout << "PART XI : Bin" << std::endl;
	std::cout << "TEST 17: Add() to Bin" << std::endl;
	Bin bin(2);
	bin.add(1, 1, 1);
	bin.add(2, 2, 2);
	bin.add(3, 3, 3);
	bin.add(4, 4, 4);
	assert(bin.getX(0) == 1);
	assert(bin.getY(1) == 2);
	assert(bin.getZ(2) == 3);

	// Test to see if we can get an element that has not been added
	//assert(bin.getX(5) == NULL);

	std::cout << "TEST 17: get Coord from Bin" << std::endl;
	std::cout << bin.getX(3) << "\t" << bin.getY(3) << "\t" << bin.getZ(3) << std::endl;
	//bin.remove(4);
	std::cout << bin.getX(2) << "\t" << bin.getY(2) << "\t" << bin.getZ(2) << std::endl;

	std::cout << "TEST 18: Copy Constructor" << std::endl;
	Bin bin2 = Bin(bin);
	bin2.add(4, 4, 4);
	bin2.remove(3);
	std::cout << bin.getX(2) << "\t" << bin.getY(2) << "\t" << bin.getZ(3) << std::endl;
	std::cout << bin2.getX(3) << std::endl;
	//"\t" << bin2.getY(3) << "\t" << bin2.getZ(3) << std::endl;

	std::cout << "TEST 19: Overloading Assignment Operator" << std::endl;
	Bin bin3(2);
	bin3 = bin;
	std::cout << bin3.getX(2) << "\t" << bin3.getY(2) << "\t" << bin3.getZ(3) << std::endl;



	return 0;
}