#pragma once
#include <iostream>

class Vector3D
{
	int X, Y, Z;
	int vector[3] = { X, Y, Z };
public:
	Vector3D(int x, int y, int z) : X{x}, Y{y}, Z{z} {}
	Vector3D operator +(const Vector3D& ot) {
		return Vector3D(X + ot.X, Y + ot.Y, Z + ot.Z);
	}
	Vector3D operator -(const Vector3D& ot) {
		return Vector3D(X - ot.X, Y - ot.Y, Z - ot.Z);
	}
	Vector3D operator *(int K) {
		return Vector3D(K * X, K * Y, K * Z);
	}
	Vector3D operator *(const Vector3D& ot) {
		return Vector3D(X * ot.X, Y * ot.Y, Z * ot.Z);
	}
	Vector3D& operator ++() {
		++X;
		++Y;
		++Z;
		return *this;
	}

	Vector3D operator ++(int) {
		Vector3D temp = *this;
		++X;
		++Y;
		++Z;
		return *this;
	}
	const int& operator [](int index) const {
		return vector[index];
	}
	Vector3D operator +=(const Vector3D& ot) {
		return Vector3D(X += ot.X, Y += ot.Y, Z += ot.Z);
	}
	Vector3D operator -=(const Vector3D& ot) {
		return Vector3D(X -= ot.X, Y -= ot.Y, Z -= ot.Z);
	}
	Vector3D operator *=(int K) {
		return Vector3D(K *= X, K *= Y, K *= Z);
	}
};

