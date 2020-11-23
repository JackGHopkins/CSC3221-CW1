#include "Vector3D.h"
#include "math.h"

Vector3D::Vector3D(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3D::~Vector3D() {}

float Vector3D::get_x() const {
	return this->x;
}

float Vector3D::get_y() const {
	return this->y;
}

float Vector3D::get_z() const {
	return this->z;
}

float Vector3D::find_Magnitude() const {
	return sqrtf(
		pow(this->x, 2.0) +
		pow(this->y, 2.0) +
		pow(this->z, 2.0)
	);
}

void Vector3D::add_V3D(Vector3D rhs) {
	this->x = x + rhs.x;
	this->y = y + rhs.y;
	this->z = z + rhs.z;
}

void Vector3D::sub_V3D(Vector3D rhs) {
	this->x = x - rhs.x;
	this->y = y - rhs.y;
	this->z = z - rhs.z;
}

void Vector3D::mult_V3D(float rhs) {
	this->x = x * rhs;
	this->y = y * rhs;
	this->z = z * rhs;
}

void Vector3D::div_V3D(float rhs) {
	this->x = x / rhs;
	this->y = y / rhs;
	this->z = z / rhs;
}

float Vector3D::dot_Prod_V3D(Vector3D rhs) const {
	return 
		(this->x * rhs.x) + 
		(this->y * rhs.y) + 
		(this->z * rhs.z);
}



Vector3D Vector3D::cross_Prod_V3D(Vector3D rhs) const {
	Vector3D v(
		(this->y * rhs.z) - (this->z * rhs.y),
		(this->z * rhs.x) - (this->x * rhs.z),
		(this->x * rhs.y) - (this->y * rhs.x)
		);
	return v;
}

void Vector3D::operator += (Vector3D rhs) {
	add_V3D(rhs);
}

void Vector3D::operator -= (Vector3D rhs) {
	sub_V3D(rhs);
}

float Vector3D::operator * (Vector3D rhs) const {
	return dot_Prod_V3D(rhs);
}

Vector3D Vector3D::operator % (Vector3D rhs) const {
	return cross_Prod_V3D(rhs);
}

Vector3D Vector3D::unit_V3D() const {
	float gradient = this->find_Magnitude();

	Vector3D v(
		this->x / gradient,
		this->y / gradient,
		this->z / gradient
	);

	return v;
}

Vector3D Vector3D::unit_Orthoganal_V3D(Vector3D rhs) const {
	Vector3D orthV = cross_Prod_V3D(rhs);
	orthV = orthV.unit_V3D();
	return orthV;
}