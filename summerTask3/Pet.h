#pragma once
#include <iostream>
#include <string>  // нужно добавить для работы string
using namespace std;

// ===============================================================
// БАЗОВЫЙ (АБСТРАКТНЫЙ) КЛАСС "ДОМАШНЕЕ ЖИВОТНОЕ"
// ===============================================================
class Pet
{
protected:
	string name;   // кличка животного
	string type;   // порода или вид животного

public:
	// Конструктор с двумя параметрами (имя и тип)
	Pet(string name, string type) : name{ name }, type{ type } { }
	
	// Делегирующий конструктор: только имя (тип пустой)
	Pet(string name) : Pet(name, "") {}
	
	// Делегирующий конструктор: без параметров (имя и тип пустые)
	Pet() : Pet("", "") { }

	// Чисто виртуальные функции (делают класс абстрактным)
	// Каждое животное должно уметь издавать звук
	virtual void Sound() = 0;
	
	// Каждое животное должно уметь показывать своё имя
	virtual void Show() = 0;
	
	// Каждое животное должно уметь показывать свой тип/породу
	virtual void Type() = 0;
};

// ===============================================================
// КЛАСС "СОБАКА" (наследник Pet)
// ===============================================================
class Dog : public Pet {
public:
	// Конструктор с именем и типом
	Dog(string name, string type) : Pet(name, type) {}
	
	// Делегирующий конструктор: только имя
	Dog(string name) : Pet(name, "") {}
	
	// Делегирующий конструктор: без параметров
	Dog() : Pet("", "") {}
	
	// Переопределяем функцию Sound() - звук собаки
	void Sound() override {
		cout << "Woof-woof!" << endl;
	}
	
	// Переопределяем функцию Show() - выводим имя
	void Show() override {
		cout << "Name: " << name << endl;
	}
	
	// Переопределяем функцию Type() - выводим породу
	void Type() override {
		cout << "Type: " << type << endl;
	}
};

// ===============================================================
// КЛАСС "КОШКА" (наследник Pet)
// ===============================================================
class Cat : public Pet {
public:
	Cat(string name, string type) : Pet(name, type) {}
	Cat(string name) : Pet(name, "") {}
	Cat() : Pet("", "") {}

	// Переопределяем функцию Sound() - звук кошки
	void Sound() override {
		cout << "Meow-meow!" << endl;
	}
	
	void Show() override {
		cout << "Name: " << name << endl;
	}
	
	void Type() override {
		cout << "Type: " << type << endl;
	}
};

// ===============================================================
// КЛАСС "ПОПУГАЙ" (наследник Pet)
// ===============================================================
class Parrot : public Pet {
public:
	Parrot(string name, string type) : Pet(name, type) {}
	Parrot(string name) : Pet(name, "") {}
	Parrot() : Pet("", "") {}

	// Переопределяем функцию Sound() - звук попугая
	void Sound() override {
		cout << "Chirp-chirp! " << endl;
	}
	
	void Show() override {
		cout << "Name: " << name << endl;
	}
	
	void Type() override {
		cout << "Type: " << type << endl;
	}
};

// ===============================================================
// КЛАСС "ХОМЯК" (наследник Pet)
// ===============================================================
class Hamster : public Pet {
public:
	Hamster(string name, string type) : Pet(name, type) {}
	Hamster(string name) : Pet(name, "") {}
	Hamster() : Pet("", "") {}

	// Переопределяем функцию Sound() - звук хомяка
	void Sound() override {
		cout << "Squeak-squeak!" << endl;
	}
	
	void Show() override {
		cout << "Name: " << name << endl;
	}
	
	void Type() override {
		cout << "Type: " << type << endl;
	}
};
