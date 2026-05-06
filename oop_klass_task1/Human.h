#include <iostream>
#include <string>
using namespace std;
#pragma once
class Human
{
	int ID;
	string Surname;
	string Name;
	string Otchestvo;

	static int countPerson;
public:
	Human(int id, string name = "", string otchestvo="", string surname="") {
		ID = id;
		Name = name;
		Otchestvo = otchestvo;
		Surname = surname;
		countPerson++;
	}

	Human() : Human(0,"","","") {}

	Human(const Human& hum) : ID{ hum.ID }, Surname{ hum.Surname }, Name{ hum.Name }, Otchestvo{ hum.Otchestvo } {
		cout << " Human copy constructed for " << this << '\n';
	}

	~Human() {
		cout << "Object destructed for " << this << '\n';
	}

	int getId() {
		return ID;
	}
	void setId(int iD) {
		ID = iD;
	}
	string getName() {
		return Name;
	}
	void setName(string name) {
		Name = name;
	}
	string getSurname() {
		return Surname;
	}
	void setSurname(string surname) {
		Surname = surname;
	}
	string getOtchestvo() {
		return Otchestvo;
	}
	void setOtchestvo(string name) {
		Otchestvo = name;
	}

	void print();

	static int Count() {
		return countPerson;
	}
};

