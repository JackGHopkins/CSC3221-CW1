#include "Vector3D.h"
#include "math.h"

/*	
	METHOD DESCRIPTIONS CAN BE FOUND IN Vector3D.h

	<Summary> .cpp file for Class Vector3D. Implements methods:
		private:	
			void addV3D(Vector3D rhs);
			void subV3D(Vector3D rhs);
			void multV3D(float rhs);
			void divV3D(float rhs);
			float dotProdV3D(Vector3D rhs) const;
			Vector3D crossProdV3D(Vector3D rhs) const;

		public:
			float getX() const ;
			float getY() const ;
			float getZ() const ;

			Vector3D(float x, float y, float z);
			Vector3D();

			float findMagnitude() const;

			void operator += (Vector3D rhs);
			void operator -= (Vector3D rhs);
			void operator * (float rhs);
			void operator / (float rhs);
			float operator *(Vector3D rhs) const;
			Vector3D operator %(Vector3D rhs) const;

			Vector3D unitV3D() const;
			Vector3D unitOrthoganalV3D(Vector3D rhs) const;

*/

Vector3D::Vector3D(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3D::Vector3D() {
	x = 0;
	y = 0;
	z = 0;
}

float Vector3D::getX() const {
	return this->x;
}

float Vector3D::getY() const {
	return this->y;
}

float Vector3D::getZ() const {
	return this->z;
}

float Vector3D::findMagnitude() const {
	return sqrtf(
		pow(this->x, 2.0) +				// Differences in effeciency between pow() and x*x was negligible. Went with pow() for readablitly.
		pow(this->y, 2.0) +
		pow(this->z, 2.0)
	);
}

void Vector3D::addV3D(Vector3D rhs) {
	this->x = x + rhs.x;
	this->y = y + rhs.y;
	this->z = z + rhs.z;
}

void Vector3D::subV3D(Vector3D rhs) {
	this->x = x - rhs.x;
	this->y = y - rhs.y;
	this->z = z - rhs.z;
}

void Vector3D::multV3D(float rhs) {
	this->x = x * rhs;
	this->y = y * rhs;
	this->z = z * rhs;
}

void Vector3D::divV3D(float rhs) {
	this->x = x / rhs;
	this->y = y / rhs;
	this->z = z / rhs;
}

float Vector3D::dotProdV3D(Vector3D rhs) const {
	return 
		(this->x * rhs.x) + 
		(this->y * rhs.y) + 
		(this->z * rhs.z);
}

Vector3D Vector3D::crossProdV3D(Vector3D rhs) const {
	Vector3D v(
		(this->y * rhs.z) - (this->z * rhs.y),
		(this->z * rhs.x) - (this->x * rhs.z),
		(this->x * rhs.y) - (this->y * rhs.x)
		);
	return v;
}

void Vector3D::operator + (Vector3D rhs) {
	addV3D(rhs);
}

void Vector3D::operator - (Vector3D rhs) {
	subV3D(rhs);
}

void Vector3D::operator * (float rhs) {
	multV3D(rhs);
}

void Vector3D::operator / (float rhs) {
	divV3D(rhs);
}

float Vector3D::operator * (Vector3D rhs) const {
	return dotProdV3D(rhs);
}

Vector3D Vector3D::operator % (Vector3D rhs) const {
	return crossProdV3D(rhs);
}

Vector3D Vector3D::unitV3D() const {
	float gradient = this->findMagnitude();

	Vector3D v(
		this->x / gradient,
		this->y / gradient,
		this->z / gradient
	);
	return v;
}

Vector3D Vector3D::unitOrthoganalV3D(Vector3D rhs) const {
	Vector3D orthV = crossProdV3D(rhs);
	orthV = orthV.unitV3D();
	return orthV;
}