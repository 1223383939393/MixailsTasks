#pragma once
#include <iostream>
using namespace std;
class Wallet
{
	double balance;
public:
	Wallet(double m) : balance{ m } {}
	Wallet() : Wallet(0) {}

	double topUp(double i) {
		return balance += i;
	}
	double spend(double i)  {
		return balance -= i;
	}
	double checkBalance()  {
		return balance;
	}
};

