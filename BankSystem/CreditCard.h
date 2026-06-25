#pragma once
#include "Card.h"
#include <iostream>
using namespace std;
class CreditCard : public Card
{
	string name;
	int number;
	double debt;
public:
	CreditCard(string n, int i, double m) : name{ n }, number{ i }, debt{ m } {}
	CreditCard(string n) : CreditCard(n, 0, 0) {}
	CreditCard(int n) : CreditCard("", n, 0) {}
	CreditCard(double n) : CreditCard("", 0, n) {}
	CreditCard() : CreditCard("", 0, 0) {}

	double topUp(double i) override {
		return debt += i;
	}
	double spend(double i) override {
		if (!(debt + i >= 100000))
		return debt -= i;
		else if (debt + i >= 100000)
		{
			cout << "You have amount of debt 100000k, pls top up card" << endl;
		}
	}
	double checkBalance() override {
		return debt;
	}
};

