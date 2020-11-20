#include "Vector3D.h"
#include <iostream>

int main(void) {

	Vector3D vector1(3, 4, 5);

	std::cout << vector1.find_Magnitude() << std::endl;

	Vector3D vector2(5, 4, 3);
	Vector3D vector3 = add_V3D(vector1, vector2);
	std::cout << vector3.x << ", " << vector3.y << ", " << vector3.z << std::endl;

	vector3 = sub_V3D(vector1, vector2);
	std::cout << vector3.x << ", " << vector3.y << ", " << vector3.z << std::endl;

	return 0;
}