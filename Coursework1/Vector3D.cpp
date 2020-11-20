#include "Vector3D.h"
#include "math.h"

Vector3D::Vector3D(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3D::~Vector3D() {}

double Vector3D::find_Magnitude() {
	return sqrt(
		pow(this->x, 2.0) +
		pow(this->y, 2.0) +
		pow(this->z, 2.0)
	);
}

Vector3D add_V3D(Vector3D vA, Vector3D vB) {
	Vector3D vC(
		vA.x + vB.x,
		vA.y + vB.y,
		vA.z + vB.z);
	return vC;
}

Vector3D sub_V3D(Vector3D vA, Vector3D vB) {
	Vector3D vC(
		vA.x - vB.x,
		vA.y - vB.y,
		vA.z - vB.z);
	return vC;
}

Vector3D Vector3D::mult_V3D(float scalar) {
	this->x = x * scalar;
	this->y = y * scalar;
	this->z = z * scalar;
}

Vector3D Vector3D::div_V3D(Vector3D v, float scalar) {
	this->x = x / scalar;
	this->y = y / scalar;
	this->z = z / scalar;
}

double dot_Prod_V3D(Vector3D vA, Vector3D vB) {
	return (vA.x * vB.x) + (vA.y * vB.y) + (vA.z * vB.z);
}

//Vector3D operator*(Vector3D va, Vector3D vB);
double cross_Prod_V3D(Vector3D vA, Vector3D vB) {
	return 0;
}

//float operator%(Vector3D vA, Vector3D vB);

//Vector3D Vector3D::unit_V3D() {
//	return;
//}

void Vector3D::set_V3D() {
}

Vector3D unit_Orthoganal_V3D(Vector3D vA, Vector3D vB) {
	return vA;
}