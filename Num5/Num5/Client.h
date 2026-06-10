#pragma once
#include <iostream>
#include "Autopark.h"
#include <vector>
using namespace std;
class Client
{
	string clientName; // создаем клиента а также список его машин, с указателем, для дочерних классов
	vector<Autopark*> clCars;
public:
	Client(string name) : clientName{ name } {} // делегация конструкторов
	Client() : Client("") { }

	string getName() {
		return clientName; // имя получить
	}
	void getClientCars() { // цикл форич(синтаксис фор) для вывода машин
		for (Autopark* car : clCars) {
			cout << car->getVehicle() << ": " << car->getPrice() << endl;
		}
	}
	void setName(string name) { // задать имя
		this->clientName = name;
	}
	void buyCar(Autopark* a) { // добавление в список
		clCars.push_back(a);
	}

};

