#pragma once
#include <iostream>
using namespace std;
class Autopark
{
	string vehicle; // базовый класс автопарка, ну машина типа я название перепутал,
	int price;

public:
	Autopark(string s, int p) : vehicle{s}, price{p} { } // делегация
	Autopark(string s) : Autopark(s, 0) { }
	Autopark(int s) : Autopark("", s) {}
	Autopark() : Autopark("", 0) {}
	string getVehicle() {
		return vehicle; // геттеры
	}
	int getPrice() {
		return price;
	}
	virtual void startCar() = 0; // виртуальный метод
};

class Cabriolet : public Autopark // наследование и переопределение метода, там дальше одинаково
{
	bool roofClosed = true;
public:
	Cabriolet(string s, int p) : Autopark(s, p) {}
	Cabriolet(string s) : Autopark(s, 0) {}
	Cabriolet(int s) : Autopark("", s) {}
	Cabriolet() : Autopark("", 0) {}
	void startCar() override {
		cout << "Cabriolet started. roof is closed" << endl;
	}
	bool isRoofClosed() {
		return roofClosed;
	}
	void closeRoof() {
		roofClosed = true;
	}
	void openRoof() {
		roofClosed = false;
	}
};

class Car : public Autopark
{
public:
	Car(string s, int p) : Autopark(s, p) {}
	Car(string s) : Autopark(s, 0) {}
	Car(int s) : Autopark("", s) {}
	Car() : Autopark("", 0) {}
	void startCar() override {
		cout << "Car started. vrom vrom" << endl;
	}
};

class Truck : public Autopark
{
public:
	Truck(string s, int p) : Autopark(s, p) {}
	Truck(string s) : Autopark(s, 0) {}
	Truck(int s) : Autopark("", s) {}
	Truck() : Autopark("", 0) {}
	void startCar() override {
		cout << "Truck started. booh booh" << endl;
	}
};