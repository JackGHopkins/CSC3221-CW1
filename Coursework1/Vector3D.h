#pragma once
/*
	<Summary>
		private:
			float x, y, z: member variables for the x, y, and z component respectively.

			void addV3D(Vector3D rhs):							Adds a vector to this vector, overwritting the value in the process.
			void subV3D(Vector3D rhs):							Subtracts a vector to this vector, overwritting the value in the process.
			void multV3D(float rhs):							Multiply this vector by a scalar, overwriting this vector in the process.
			void divV3D(float rhs):								Divide this vector by a scalar, overwriting this vector in the process.
			float dotProdV3D(Vector3D rhs) const:				Finds the Dot/Scalar Product of two given vectors. Returns a float.
			Vector3D crossProdV3D(Vector3D rhs) const:			Finds the Cross/Vector Product of two given vectors. Returns a Vector3D

		public:
			float getX() const,
			float getY() const,
			float getZ() const:									Returns an x,y or z component of a vector.
			
			Vector3D(float x, float y, float z):				Constructor taking and x, y, and z parameter for each component respectively.
			Vector3D():											Constructor for when no parameters are given.
			
			float findMagnitude() const:						Computes the magnitude of a vector. Returns a float.
			
																Overloaded Operators for:	
			void operator += (Vector3D rhs):					- addV3D(Vector3D rhs)
			void operator -= (Vector3D rhs):					- subV3D(Vector3D rhs)
			void operator * (float rhs):						- multV3D(float rhs)
			void operator / (float rhs):						- divV3D(float rhs)
			float operator *(Vector3D rhs) const:				- dotProdV3D(Vector3D rhs)
			Vector3D operator %(Vector3D rhs) const:			- crossProdV3D(Vector3D rhs)	
			
			Vector3D unitV3D() const:							Produces a unit vector (one of magnitude 1) pointing in the same direction as a given vector.
			Vector3D unitOrthoganalV3D(Vector3D rhs) const:		Returns a unit vector orthogonal to two given vectors.
*/
class Vector3D {
private:
	float x, y, z;

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
	
	void operator + (Vector3D rhs);
	void operator - (Vector3D rhs);
	void operator * (float rhs);
	void operator / (float rhs);
	float operator *(Vector3D rhs) const;
	Vector3D operator %(Vector3D rhs) const;

	Vector3D unitV3D() const;
	Vector3D unitOrthoganalV3D(Vector3D rhs) const;
};