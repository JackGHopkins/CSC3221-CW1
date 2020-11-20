#pragma once

class Vector3D {
public:
	double x, y, z;

	Vector3D(double x, double y, double z);
	~Vector3D();
	double find_Magnitude();

	Vector3D mult_V3D(float scalar);
	Vector3D div_V3D(Vector3D v, float scalar);

	Vector3D unit_V3D();
	void set_V3D();

};

Vector3D add_V3D(Vector3D vA, Vector3D vB);
Vector3D sub_V3D(Vector3D vA, Vector3D vB);

double dot_Prod_V3D(Vector3D vA, Vector3D vB);
//Vector3D operator*(Vector3D va, Vector3D vB);
double sclr_Prod_V3D(Vector3D vA, Vector3D vB);
//float operator%(Vector3D vA, Vector3D vB);

Vector3D unit_Orthoganal_V3D(Vector3D vA, Vector3D vB);