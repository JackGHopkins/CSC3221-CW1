#pragma once

class Vector3D {
private:
	float x, y, z;
public:
	float get_x() const ;
	float get_y() const ;
	float get_z() const ;

	Vector3D(float x, float y, float z);
	~Vector3D();
	float find_Magnitude() const;

	void add_V3D(Vector3D rhs);
	void sub_V3D(Vector3D rhs);
	void mult_V3D(float rhs);
	void div_V3D(float rhs);

	float dot_Prod_V3D(Vector3D rhs) const;
	Vector3D cross_Prod_V3D(Vector3D rhs) const;
	
	void operator += (Vector3D rhs);
	void operator -= (Vector3D rhs);
	float operator *(Vector3D rhs) const;
	Vector3D operator %(Vector3D rhs) const;

	Vector3D unit_V3D() const;
	Vector3D unit_Orthoganal_V3D(Vector3D rhs) const;
};