#pragma once
#include <iostream>
using namespace std;
class Employer
{
	string name;
	int age;
public: 
	virtual void Print() = 0;
};

class President : public Employer
{
	string companyName;
	int allMoney;
public:
	void Print() override {
		cout << "What`s your company name? " << companyName << " How much money do u have? " << allMoney << endl;
	}
};

class Manager : public Employer
{
	int workersCount;
public:
	void Print() override {
		cout << "How many subordinates do u have? " << workersCount << endl;
	}
};

class Worker : public Employer
{
	int salary;
public:
	void Print() override {
		cout << "What salary do u have? " << salary << endl;
	}
};

