#pragma once
#include <iostream>
using namespace std;
class Card
{
	string name;
	int number;
	double balance;

public:
	//делегация
	Card(string n, int i, double m) : name{n}, number{i}, balance{m} { }
	Card(string n) : Card(n, 0, 0) {}
	Card(int n) : Card("", n, 0) {}
	Card(double n) : Card("", 0, n) {}
	Card() : Card("", 0, 0) {}

	virtual double topUp(double i) = 0;
	virtual double spend(double i) = 0;
	virtual double checkBalance() = 0;
};

