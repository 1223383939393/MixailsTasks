#pragma once
#include <iostream>
#include <string>  // Добавлено для string (у тебя было забыто)
using namespace std;

// ===============================================================
// БАЗОВЫЙ (АБСТРАКТНЫЙ) КЛАСС "ТРАНСПОРТНОЕ СРЕДСТВО"
// ===============================================================
class Venicle
{
    string model;   // Модель транспорта (например "Toyota", "Stels")
    int year;       // Год выпуска (например 2020)

protected:
    int rate;       // Тариф за 1 км в рублях (доступен наследникам)

public:
    // Конструкторы - разные способы создать объект
    Venicle(string model, int year) : model{ model }, year{ year } {}
    Venicle(string model) : Venicle(model, 0) {}        // если нет года
    Venicle(int year) : Venicle("", year) {}            // если нет модели
    Venicle() : Venicle("", 0) {}                       // если ничего нет

    // Чисто виртуальная функция = 0 означает, что этот класс абстрактный
    // Нельзя создать объект Venicle, только наследников
    // Должна быть переопределена в каждом наследнике
    virtual int getTime(int length, int speed) = 0;

    // Ещё одна чисто виртуальная функция
    virtual int getCost(int length) = 0;
};

// ===============================================================
// КЛАСС "АВТОМОБИЛЬ" - наследник Venicle
// ===============================================================
class Car1 : public Venicle {
public:
    // Конструкторы - все вызывают конструктор Venicle и устанавливают тариф 10 руб/км
    Car1(string model, int year) : Venicle(model, year) { rate = 10; }
    Car1(string model) : Venicle(model, 0) { rate = 10; }
    Car1(int year) : Venicle("", year) { rate = 10; }
    Car1() : Venicle("", 0) { rate = 10; }

    // Переопределяем функцию расчёта времени
    // Формула: время = расстояние / скорость (целочисленное деление)
    int getTime(int length, int speed) override {
        return length / speed;
    }

    // Переопределяем функцию расчёта стоимости
    // Формула: стоимость = расстояние * тариф (10 руб/км)
    int getCost(int length) override {
        return length * rate;
    }
};

// ===============================================================
// КЛАСС "ВЕЛОСИПЕД" - наследник Venicle
// ===============================================================
class Bike : public Venicle {
public:
    // Конструкторы - тариф 2 руб/км
    Bike(string model, int year) : Venicle(model, year) { rate = 2; }
    Bike(string model) : Venicle(model, 0) { rate = 2; }
    Bike(int year) : Venicle("", year) { rate = 2; }
    Bike() : Venicle("", 0) { rate = 2; }

    // Время = расстояние / скорость
    int getTime(int length, int speed) override {
        return length / speed;
    }

    // Стоимость = расстояние * 2 руб/км
    int getCost(int length) override {
        return length * rate;
    }
};

// ===============================================================
// КЛАСС "ПОВОЗКА" - наследник Venicle
// ===============================================================
class Carriage : public Venicle {
public:
    // Конструкторы - тариф 4 руб/км
    Carriage(string model, int year) : Venicle(model, year) { rate = 4; }
    Carriage(string model) : Venicle(model, 0) { rate = 4; }
    Carriage(int year) : Venicle("", year) { rate = 4; }
    Carriage() : Venicle("", 0) { rate = 4; }

    // Время = расстояние / скорость
    int getTime(int length, int speed) override {
        return length / speed;
    }

    // Стоимость = расстояние * 4 руб/км
    int getCost(int length) override {
        return length * rate;
    }
};