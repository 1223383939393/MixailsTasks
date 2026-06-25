#pragma once
#include "Card.h"
#include <iostream>
using namespace std;
class DebitCard : public Card
{
	string name;
	int number;
	double balance;
public:
	DebitCard(string n, int i, double m) : name{ n }, number{ i }, balance{ m } {}
	DebitCard(string n) : DebitCard(n, 0, 0) {}
	DebitCard(int n) : DebitCard("", n, 0) {}
	DebitCard(double n) : DebitCard("", 0, n) {}
	DebitCard() : DebitCard("", 0, 0) {}

	double topUp(double i) override {
		return balance += i;
	}
	double spend(double i) override {
		return balance -= i;
	}
	double checkBalance() override {
		return balance;
	}
};

