#pragma once
#include<string>
#include<iostream>
using namespace std;
class Termometer
{
	double celsius = 0;
	const char* location;
	string text;
public:
	Termometer() {
		location = "Unknown";
		celsius = 0.0;
	}
	Termometer(double tempCelsius) {
		celsius = tempCelsius;
		location = "Unknown";
	}
	Termometer(const char* place, double tempCelsius) {
		location = place;
		celsius = tempCelsius;
	}
	double getCelcius() {
		return celsius;
	}
	double getFahrenheit() {
		double F = celsius * (9 / 5) + 32;
		return F;
	}
	void printInfo() {
		cout << "Temperature in celcius: " << celsius << endl;
		cout << "Location: " << location << endl;
	}
	// интересный факт для михаила: как то нам матвей максимыч давал задание сделать прогу для погоды используя реальную погоду, но я не помню как это сделать)))) не знаю зачем я это написал :3
};

