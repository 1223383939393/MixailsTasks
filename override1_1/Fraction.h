#pragma once
#include <iostream>
using namespace std;
class Fraction
{
private:
	int NOD(int a, int b) {
		int nod;
		if (a > b) {
			for (int i = 1; i <= a; i++) {
				if (a % i == 0 && b % i == 0) {
					nod = i;
				}
			}
			return nod;
		}
		else if (a < b) {
			for (int i = 1; i <= b; i++) {
				if (a % i == 0 && b % i == 0) {
					nod = i;
				}
			}
			return nod;
		}
	}
public:
	int a, b;
	Fraction(int x, int y) : a{x}, b{y} {}
	Fraction operator +(const Fraction& ot) {
		int chisl = a * ot.b + ot.a * b;
		int znam = b * ot.b;
		int res = NOD(chisl, znam);
		return Fraction(chisl / res, znam / res);
	}
	Fraction operator -(const Fraction& ot) {
		int chisl = a * ot.b - ot.a * b;
		int znam = b * ot.b;
		int res = NOD(chisl, znam);
		return Fraction(chisl / res, znam / res);
	}
	Fraction operator *(const Fraction& ot) {
		int chisl = this->a * ot.a;
		int znam = this->b * ot.b;
		int res = NOD(chisl, znam);
		return Fraction(chisl / res, znam / res);
	}
	Fraction operator /(const Fraction& ot) {
		int chisl = this->a * ot.b;
		int znam = this->b * ot.a;
		int res = NOD(chisl, znam);
		return Fraction(chisl / res, znam / res);
	}
	bool operator ==(const Fraction& ot) {
		return this->a * ot.b == ot.a * b;
	}
	bool operator !=(const Fraction& ot) {
		return this->a != ot.a || this->b != ot.b;
	}
	bool operator >(const Fraction& ot) {
		return this->a * ot.b > ot.a * b;
	}
	bool operator <(const Fraction& ot) {
		return this->a * ot.b < ot.a * b;
	}
	friend ostream& operator <<(ostream& is, const Fraction& ot) {
		is << ot.a << "/" << ot.b << endl;
		return is;
	}
	friend istream& operator >>(istream& is, Fraction& ot) {
		cout << "Enter x and y ";
		is >> ot.a >> ot.b;
		return is;
	}
};

