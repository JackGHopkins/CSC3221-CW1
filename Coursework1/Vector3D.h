#pragma once

class Vector3D {
private:
	float x, y, z;
public:
	float getX() const ;
	float getY() const ;
	float getZ() const ;

	Vector3D(float x, float y, float z);
	Vector3D();

	float findMagnitude() const;

	void addV3D(Vector3D rhs);
	void subV3D(Vector3D rhs);
	void multV3D(float rhs);
	void divV3D(float rhs);

	float dotProdV3D(Vector3D rhs) const;
	Vector3D crossProdV3D(Vector3D rhs) const;
	
	void operator += (Vector3D rhs);
	void operator -= (Vector3D rhs);
	float operator *(Vector3D rhs) const;
	Vector3D operator %(Vector3D rhs) const;

	Vector3D unitV3D() const;
	Vector3D unitOrthoganalV3D(Vector3D rhs) const;
};