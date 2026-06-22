#pragma once
#include <iostream>
#include <string>
using namespace std;

// ===============================================================
// КЛАСС "КОЛЕСА"
// Хранит информацию о колесах автомобиля
// ===============================================================
class Wheels {
    int wheelsCount;      // количество колес
    double wheelRadius;   // радиус колеса в дюймах
    string wheelType;     // тип колес (летние, зимние, всесезонные)

public:
    // Главный конструктор (с параметрами)
    // Принимает: количество, радиус, тип колес
    Wheels(int count, double radius, string type)
        : wheelsCount(count), wheelRadius(radius), wheelType(type) {
    }

    // Делегирующий конструктор: только count и radius
    // Тип колес по умолчанию пустой
    Wheels(int count, double radius) : Wheels(count, radius, "") {}

    // Делегирующий конструктор: только count
    // Радиус по умолчанию 0, тип пустой
    Wheels(int count) : Wheels(count, 0, "") {}

    // Делегирующий конструктор: без параметров
    // По умолчанию: 0 колес, радиус 0, тип пустой
    Wheels() : Wheels(0, 0, "") {}

    // Вывод информации о колесах
    void showInfo() const {
        cout << "Wheels: " << wheelsCount << ", radius=" << wheelRadius << ", type=" << wheelType << endl;
    }
};

// ===============================================================
// КЛАСС "ДВИГАТЕЛЬ"
// Хранит информацию о двигателе автомобиля
// ===============================================================
class Engine {
    int enginePower;      // мощность двигателя в лошадиных силах
    double engineVolume;  // объем двигателя в литрах
    string engineType;    // тип двигателя (бензин, дизель, электрический)

public:
    // Главный конструктор
    // Принимает: мощность, объем, тип двигателя
    Engine(int power, double volume, string type)
        : enginePower(power), engineVolume(volume), engineType(type) {
    }

    // Делегирующий: только power и volume
    // Тип двигателя по умолчанию "petrol"
    Engine(int power, double volume) : Engine(power, volume, "petrol") {}

    // Делегирующий: только power
    // Объем по умолчанию 2.0, тип "petrol"
    Engine(int power) : Engine(power, 2.0, "petrol") {}

    // Делегирующий: без параметров
    // По умолчанию: 150 л.с., объем 2.0, тип "petrol"
    Engine() : Engine(150, 2.0, "petrol") {}

    // Вывод информации о двигателе
    void showInfo() const {
        cout << "Power: " << enginePower << ", Volume:" << engineVolume << ", type=" << engineType << endl;
    }
};

// ===============================================================
// КЛАСС "ДВЕРИ"
// Хранит информацию о дверях автомобиля
// ===============================================================
class Door {
    int doorCount;       // количество дверей
    bool doorOpened;     // состояние дверей (true - открыты, false - закрыты)

public:
    // Главный конструктор
    // Принимает: количество дверей, состояние (открыты/закрыты)
    Door(int count, bool opened) : doorCount(count), doorOpened(opened) {}

    // Делегирующий: только количество дверей
    // Двери по умолчанию закрыты (false)
    Door(int count) : Door(count, false) {}

    // Делегирующий: без параметров
    // По умолчанию: 4 двери, закрыты
    Door() : Door(4, false) {}

    // Вывод информации о дверях
    // Тернарный оператор ? : выводит "yes" если true, "no" если false
    void showInfo() const {
        cout << "How many doors: " << doorCount << ", Door opened: " << (doorOpened ? "yes" : "no") << endl;
    }
};

// ===============================================================
// КЛАСС "АВТОМОБИЛЬ"
// Объединяет все компоненты (колеса, двигатель, двери) через множественное наследование
// ===============================================================
class Vehicle : public Wheels, public Engine, public Door {
    string carModel;   // модель автомобиля
    int carYear;       // год выпуска автомобиля

public:
    // Главный конструктор (принимает все параметры для всех частей автомобиля)
    Vehicle(string model, int year,
        int wCount, double wRadius, string wType,
        int ePower, double eVolume, string eType,
        int dCount, bool dOpened)
        : carModel(model), carYear(year),
        Wheels(wCount, wRadius, wType),
        Engine(ePower, eVolume, eType),
        Door(dCount, dOpened) {
    }

    // Делегирующий: модель, год + колеса по умолчанию
    // Колеса: 4 шт, радиус 16, тип "summer"
    Vehicle(string model, int year,
        int ePower, double eVolume, string eType,
        int dCount, bool dOpened)
        : Vehicle(model, year, 4, 16.0, "summer", ePower, eVolume, eType, dCount, dOpened) {
    }

    // Делегирующий: модель, год + двигатель и двери по умолчанию
    // Двигатель: 150 л.с., объем 2.0, тип "petrol"
    // Двери: 4 шт, закрыты
    Vehicle(string model, int year, int wCount, double wRadius, string wType)
        : Vehicle(model, year, wCount, wRadius, wType, 150, 2.0, "petrol", 4, false) {
    }

    // Делегирующий: только модель и год
    // Всё остальное по умолчанию
    Vehicle(string model, int year)
        : Vehicle(model, year, 4, 16.0, "summer", 150, 2.0, "petrol", 4, false) {
    }

    // Делегирующий: без параметров
    // Модель "Unknown", год 2020, остальное по умолчанию
    Vehicle() : Vehicle("Unknown", 2020, 4, 16.0, "summer", 150, 2.0, "petrol", 4, false) {}

    // Вывод полной информации об автомобиле
    // Вызывает методы showInfo() всех родительских классов
    void showCar() const {
        cout << "\n========== CAR ==========" << endl;
        cout << "Model: " << carModel << ", Year: " << carYear << endl;
        Wheels::showInfo();   // вызываем метод класса Wheels
        Engine::showInfo();   // вызываем метод класса Engine
        Door::showInfo();     // вызываем метод класса Door
        cout << "========================" << endl;
    }
};
