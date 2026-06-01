#pragma once
#include <iostream>
using namespace std;
class Pet
{
protected:
	string name;
	string type;
public:
	Pet(string name, string type) : name{name}, type{type} { }
	Pet(string name) : Pet(name, "") {}
	Pet() : Pet("", "") { }

	virtual void Sound() = 0;
	virtual void Show() = 0;
	virtual void Type() = 0;
};

class Dog : public Pet {
public:
	Dog(string name, string type) : Pet(name, type) {}
	Dog(string name) : Pet(name, "") {}

	Dog() : Pet("", "") {}
	
	void Sound() override {
		cout << "Woof-woof!" << endl;
	}
	void Show() override {
		cout << "Name: " << name << endl;;
	}
	void Type() override {
		cout << "Type: " << type << endl;
	}
};

class Cat : public Pet {
public:
	Cat(string name, string type) : Pet(name, type) {}
	Cat(string name) : Pet(name, "") {}

	Cat() : Pet("", "") {}

	void Sound() override {
		cout << "Meow-meow!" << endl;
	}
	void Show() override {
		cout << "Name: " << name << endl;;
	}
	void Type() override {
		cout << "Type: " << type << endl;
	}
};

class Parrot : public Pet {
public:
	Parrot(string name, string type) : Pet(name, type) {}
	Parrot(string name) : Pet(name, "") {}

	Parrot() : Pet("", "") {}

	void Sound() override {
		cout << "Chirp-chirp! " << endl;
	}
	void Show() override {
		cout << "Name: " << name << endl;;
	}
	void Type() override {
		cout << "Type: " << type << endl;
	}
};

class Hamster : public Pet {
public:
	Hamster(string name, string type) : Pet(name, type) {}
	Hamster(string name) : Pet(name, "") {}

	Hamster() : Pet("", "") {}

	void Sound() override {
		cout << "Squeak-squeak!" << endl;
	}
	void Show() override {
		cout << "Name: " << name << endl;;
	}
	void Type() override {
		cout << "Type: " << type << endl;
	}
};


