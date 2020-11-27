#include "Vector3D.h"
#include "Bin.h"
#include <iostream>
#include "assert.h"

/*
	<Summary>
		testVector3D(): Runs tests for each method in the Vector3D Class.
		testBin(): Runs tests for each method in the Bin Class.
		main(): Main Function
*/
void testVector3D();
void testBin();

int main(void) {
	testVector3D();
	testBin();
	return 0;
}

/*
	TESTING VECTOR3D
*/
void testVector3D() {
	Vector3D vector1(1, 2, 2);
	Vector3D vector2(-1, 2, 2);
	Vector3D vector3(2, 1, 1);
	Vector3D vector4(5, 5, 5);

	std::cout << "TESTING VECTOR3D" << std::endl;

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
	vector1 + vector3;
	assert(vector1.getX() == 3);
	assert(vector1.getY() == 3);
	assert(vector1.getZ() == 3);
	std::cout << "TEST 6: sub_V3D()" << std::endl;
	vector1 - vector3;
	assert(vector1.getX() == 1);
	assert(vector1.getY() == 2);
	assert(vector1.getZ() == 2);
	std::cout << "" << std::endl;


	// PART IV
	std::cout << "PART IV: 'operators to multiply and divide a vector by a scalar'" << std::endl;
	std::cout << "TEST 7: mult_V3D()" << std::endl;
	vector1 * 2;
	assert(vector1.getX() == 2);
	assert(vector1.getY() == 4);
	assert(vector1.getZ() == 4);

	std::cout << "TEST 8: div_V3D()" << std::endl;
	vector1 / 2;
	assert(vector1.getX() == 1);
	assert(vector1.getY() == 2);
	assert(vector1.getZ() == 2);
	std::cout << "" << std::endl;


	// PART V
	std::cout << "PART V: 'calculate the scalar and vector product of two vectors'" << std::endl;
	std::cout << "TEST 9: dot_Prod_V3D()" << std::endl;
	float f1 = vector1 * vector4;
	assert(f1 == 25);

	std::cout << "TEST 10: cross_Prod_V3D()" << std::endl;
	Vector3D vector5 = vector1 % vector4;
	assert(vector5.getX() == 0);
	assert(vector5.getY() == 5);
	assert(vector5.getZ() == -5);
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
	mag = (vector1 % vector4).findMagnitude();
	assert(vector1UnitOrth.getX() == (0 / mag));
	assert(vector1UnitOrth.getY() == (5 / mag));
	assert(vector1UnitOrth.getZ() == (-5 / mag));

	std::cout << "---- END OF VECTOR3D TESTS ----" << std::endl;
	std::cout << "" << std::endl;

}

/*
	TESTING BIN
*/
void testBin() {

	Bin bin(2);							// Intialise bin with a m_MaxSize of 2.

	std::cout << "TESTING BIN" << std::endl;

	std::cout << "TEST 1: add()" << std::endl;
	bin.add(1, 1, 1);					// Adding Elements to the Array
	bin.add(2, 2, 2);
	bin.add(3, 3, 3);					// Adding Elements to the Array, exceeding its MaxSize. Array should expand and add additional elements.
	bin.add(4, 4, 4);

	std::cout << "TEST 2:getX(), getY() and getZ()" << std::endl;
	assert(bin.getX(0) == 1);			// Gets X and elements that have just been added.
	assert(bin.getY(1) == 2);
	assert(bin.getZ(2) == 3);

	// Test to see if we can get an element that has not been added.
	std::cout << "Should Print Out: INVALID ELEMENT: Could not getX()" << std::endl;
	bin.getX(5);	// Console should print out "INVALID ELEMENT: Could not getX()"

	std::cout << "TEST 3: remove()" << std::endl;
	assert(bin.getX(2) == 3);	// Asserting x, y and z components before remove()
	assert(bin.getY(2) == 3);
	assert(bin.getZ(2) == 3);
	bin.remove(2);
	assert(bin.getX(2) == 4);	// Asserting x, y and z components after remove()
	assert(bin.getY(2) == 4);
	assert(bin.getZ(2) == 4);

	// Test to see if the highest element was moved.
	std::cout << "Should Print Out: INVALID ELEMENT: Could not getX()" << std::endl;
	bin.getX(3);	// Console should print out "INVALID ELEMENT: Could not getX()"


	std::cout << "TEST 4: Copy Constructor and Assignment Operator" << std::endl;
	Bin bin2 = Bin(bin);
	assert(bin.getX(0) == bin2.getX(0));
	assert(bin.getY(0) == bin2.getY(0));
	assert(bin.getZ(0) == bin2.getZ(0));
	bin2.add(4, 4, 4);
	bin2.remove(0);
	assert(bin.getX(0) != bin2.getX(0));
	assert(bin.getY(0) != bin2.getY(0));
	assert(bin.getZ(0) != bin2.getZ(0));


	std::cout << "---- END OF BIN TESTS ----" << std::endl;
	std::cout << "" << std::endl;
}